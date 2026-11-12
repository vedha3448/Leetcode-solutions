/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

void solve(int row, int n, char*** result,
           int* returnSize, int* cols,
           int* diag1, int* diag2, char** board) {

    if (row == n) {
        char** solution = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            solution[i] = malloc((n + 1) * sizeof(char));
            strcpy(solution[i], board[i]);
        }

        result[*returnSize] = solution;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {

        int d1 = row - col + n - 1;
        int d2 = row + col;

        if (cols[col] || diag1[d1] || diag2[d2])
            continue;

        board[row][col] = 'Q';

        cols[col] = 1;
        diag1[d1] = 1;
        diag2[d2] = 1;

        solve(row + 1, n, result, returnSize,
              cols, diag1, diag2, board);

        board[row][col] = '.';

        cols[col] = 0;
        diag1[d1] = 0;
        diag2[d2] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize,
                     int** returnColumnSizes) {

    char*** result = malloc(1000 * sizeof(char**));

    char** board = malloc(n * sizeof(char*));

    int* cols = calloc(n, sizeof(int));
    int* diag1 = calloc(2 * n - 1, sizeof(int));
    int* diag2 = calloc(2 * n - 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        board[i] = malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    *returnSize = 0;

    solve(0, n, result, returnSize,
          cols, diag1, diag2, board);

    *returnColumnSizes = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    for (int i = 0; i < n; i++)
        free(board[i]);

    free(board);
    free(cols);
    free(diag1);
    free(diag2);

    return result;
}
