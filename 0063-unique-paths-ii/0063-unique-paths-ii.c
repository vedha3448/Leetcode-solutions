
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                             int* obstacleGridColSize) {

    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];

    int dp[101][101] = {0};

    // If starting position has an obstacle
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // If obstacle is present
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }

            else {
                // Add paths from top
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }

                // Add paths from left
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }

    return dp[m - 1][n - 1];
}
