
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - 
           (*(int *)a < *(int *)b);
}

int minimizeSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);

    int ans = INT_MAX;

    for (int i = 0; i < 3; i++) {
        int diff = nums[numsSize - 1 - (2 - i)] - nums[i];

        if (diff < ans) {
            ans = diff;
        }
    }

    return ans;
}
