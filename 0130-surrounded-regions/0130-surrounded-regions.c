

#include <stdlib.h>

void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];

    int *queue = malloc(m * n * sizeof(int));

    if (queue == NULL)
        return;

    int front = 0;
    int rear = 0;

    // Check first and last columns
    for (int i = 0; i < m; i++) {
        if (board[i][0] == 'O') {
            board[i][0] = '#';
            queue[rear++] = i * n;
        }

        if (n > 1 && board[i][n - 1] == 'O') {
            board[i][n - 1] = '#';
            queue[rear++] = i * n + n - 1;
        }
    }

    // Check first and last rows
    for (int j = 0; j < n; j++) {
        if (board[0][j] == 'O') {
            board[0][j] = '#';
            queue[rear++] = j;
        }

        if (m > 1 && board[m - 1][j] == 'O') {
            board[m - 1][j] = '#';
            queue[rear++] = (m - 1) * n + j;
        }
    }

    // BFS traversal
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (front < rear) {
        int pos = queue[front++];

        int x = pos / n;
        int y = pos % n;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < m &&
                ny >= 0 && ny < n &&
                board[nx][ny] == 'O') {

                board[nx][ny] = '#';
                queue[rear++] = nx * n + ny;
            }
        }
    }

    // Convert the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';

            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }

    free(queue);
}
