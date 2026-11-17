
#include <stdbool.h>
#include <string.h>

bool dfs(char** board, int m, int n, char* word,
         int r, int c, int index) {

    // All characters matched
    if (word[index] == '\0') {
        return true;
    }

    // Check boundaries and character match
    if (r < 0 || r >= m || c < 0 || c >= n ||
        board[r][c] != word[index]) {
        return false;
    }

    // Mark the cell as visited
    char temp = board[r][c];
    board[r][c] = '#';

    // Search in four directions
    bool found =
        dfs(board, m, n, word, r - 1, c, index + 1) ||
        dfs(board, m, n, word, r + 1, c, index + 1) ||
        dfs(board, m, n, word, r, c - 1, index + 1) ||
        dfs(board, m, n, word, r, c + 1, index + 1);

    // Restore the original character
    board[r][c] = temp;

    return found;
}

bool exist(char** board, int boardSize,
           int* boardColSize, char* word) {

    int m = boardSize;
    int n = boardColSize[0];

    // Try starting from every cell
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (dfs(board, m, n, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}
