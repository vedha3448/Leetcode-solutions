/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int *nums, int n, int start,
               int *temp, int size,
               int **ans, int *returnSize,
               int **returnColumnSizes) {

    ans[*returnSize] = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        ans[*returnSize][i] = temp[i];
    }

    (*returnColumnSizes)[*returnSize] = size;
    (*returnSize)++;

    for (int i = start; i < n; i++) {

        if (i > start && nums[i] == nums[i - 1])
            continue;

        temp[size] = nums[i];

        backtrack(nums, n, i + 1, temp, size + 1,
                  ans, returnSize, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize,
                     int* returnSize,
                     int** returnColumnSizes) {

    qsort(nums, numsSize, sizeof(int), compare);

    int max = 1 << numsSize;

    int **ans = malloc(max * sizeof(int *));
    *returnColumnSizes = malloc(max * sizeof(int));

    int temp[10];
    *returnSize = 0;

    backtrack(nums, numsSize, 0, temp, 0,
              ans, returnSize, returnColumnSizes);

    return ans;
}
