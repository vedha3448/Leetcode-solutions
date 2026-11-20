

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) -
           (*(int *)a < *(int *)b);
}

int maxSelectedElements(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int *dp = (int *)calloc(1000002, sizeof(int));

    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];

        dp[x + 1] = dp[x] + 1;
        dp[x] = dp[x - 1] + 1;

        if (dp[x] > ans)
            ans = dp[x];

        if (dp[x + 1] > ans)
            ans = dp[x + 1];
    }

    free(dp);

    return ans;
}
