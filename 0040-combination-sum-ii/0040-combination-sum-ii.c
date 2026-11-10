/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize,
               int** result, int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        result[*returnSize] = malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++) {
            result[*returnSize][i] = path[i];
        }

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {

        // Skip duplicate numbers at the same level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Since array is sorted, no need to check further
        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];

        // Move to i + 1 because each element is used once
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i + 1,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize,
                      int target, int* returnSize,
                      int** returnColumnSizes) {

    *returnSize = 0;

    qsort(candidates, candidatesSize, sizeof(int), compare);

    int** result = malloc(10001 * sizeof(int*));
    *returnColumnSizes = malloc(10001 * sizeof(int));

    int* path = malloc(31 * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0,
              path, 0, result, returnSize, returnColumnSizes);

    free(path);

    return result;
}
