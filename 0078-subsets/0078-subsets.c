/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#include <stdlib.h>

void backtrack(int* nums, int numsSize, int index,
               int* current, int size,
               int** result, int* returnSize,
               int** returnColumnSizes) {

    // Store the current subset
    result[*returnSize] = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        result[*returnSize][i] = current[i];
    }

    (*returnColumnSizes)[*returnSize] = size;
    (*returnSize)++;

    // Generate remaining subsets
    for (int i = index; i < numsSize; i++) {

        current[size] = nums[i];

        backtrack(nums, numsSize, i + 1,
                  current, size + 1,
                  result, returnSize,
                  returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize,
              int* returnSize, int** returnColumnSizes) {

    // Total number of subsets
    int total = 1 << numsSize;

    int** result = malloc(total * sizeof(int*));

    *returnColumnSizes = malloc(total * sizeof(int));

    *returnSize = 0;

    int current[10];

    backtrack(nums, numsSize, 0,
              current, 0,
              result, returnSize,
              returnColumnSizes);

    return result;
}
