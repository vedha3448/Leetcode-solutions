/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 */

void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize,
               int** result, int* returnSize,
               int** returnColumnSizes) {

    // Target reached: store the combination
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

        // If candidate is greater than target, skip it
        if (candidates[i] > target)
            continue;

        // Choose the candidate
        path[pathSize] = candidates[i];

        // Reuse the same candidate (i, not i + 1)
        backtrack(candidates, candidatesSize, target - candidates[i],
                  i, path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {

    *returnSize = 0;

    int** result = malloc(150 * sizeof(int*));
    *returnColumnSizes = malloc(150 * sizeof(int));

    int* path = malloc(41 * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0,
              path, 0, result, returnSize, returnColumnSizes);

    free(path);

    return result;
}
