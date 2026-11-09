
bool isSafe(char** board, int row, int col, char num) {

    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return false;

        if (board[i][col] == num)
            return false;
    }

    // Check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(char** board) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {

                for (char num = '1'; num <= '9'; num++) {

                    if (isSafe(board, i, j, num)) {

                        board[i][j] = num;

                        if (solve(board))
                            return true;

                        // Backtracking
                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}
