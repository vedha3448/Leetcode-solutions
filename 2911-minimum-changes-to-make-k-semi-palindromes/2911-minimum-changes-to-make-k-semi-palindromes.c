
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int cost[205][205];
int dp[205][205];

int semiCost(char *s, int l, int r) {
    int len = r - l + 1;
    int ans = INT_MAX;

    // Try every proper divisor of the substring length
    for (int d = 1; d < len; d++) {
        if (len % d != 0)
            continue;

        int changes = 0;

        // Check each group
        for (int i = 0; i < d; i++) {
            int left = l + i;
            int right = r - (d - 1 - i);

            while (left < right) {
                if (s[left] != s[right])
                    changes++;

                left += d;
                right -= d;
            }
        }

        if (changes < ans)
            ans = changes;
    }

    return ans;
}

int minimumChanges(char* s, int k) {
    int n = strlen(s);

    // Precompute substring costs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cost[i][j] = semiCost(s, i, j);
        }
    }

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }

    dp[0][0] = 0;

    // Divide string into exactly k substrings
    for (int parts = 1; parts <= k; parts++) {
        for (int i = 2 * parts; i <= n; i++) {
            for (int j = 2 * (parts - 1); j <= i - 2; j++) {

                int currentCost = cost[j][i - 1];

                int total = dp[j][parts - 1] + currentCost;

                if (total < dp[i][parts]) {
                    dp[i][parts] = total;
                }
            }
        }
    }

    return dp[n][k];
}
