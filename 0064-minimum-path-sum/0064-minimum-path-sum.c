
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int dp[200][200];

    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the remaining cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int min = dp[i - 1][j] < dp[i][j - 1]
                      ? dp[i - 1][j]
                      : dp[i][j - 1];

            dp[i][j] = grid[i][j] + min;
        }
    }

    return dp[m - 1][n - 1];
}
