/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned in *returnColumnSizes.
 * Both returned arrays must be malloced.
 */
int** insert(int** intervals, int intervalsSize,
             int* intervalsColSize, int* newInterval,
             int newIntervalSize, int* returnSize,
             int** returnColumnSizes) {

    int **result = malloc((intervalsSize + 1) * sizeof(int *));
    *returnColumnSizes = malloc((intervalsSize + 1) * sizeof(int));

    int count = 0;
    int i = 0;

    // Step 1: Add intervals before newInterval
    while (i < intervalsSize &&
           intervals[i][1] < newInterval[0]) {

        result[count] = malloc(2 * sizeof(int));

        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];

        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    // Step 2: Merge overlapping intervals
    while (i < intervalsSize &&
           intervals[i][0] <= newInterval[1]) {

        if (intervals[i][0] < newInterval[0]) {
            newInterval[0] = intervals[i][0];
        }

        if (intervals[i][1] > newInterval[1]) {
            newInterval[1] = intervals[i][1];
        }

        i++;
    }

    // Add the merged newInterval
    result[count] = malloc(2 * sizeof(int));

    result[count][0] = newInterval[0];
    result[count][1] = newInterval[1];

    (*returnColumnSizes)[count] = 2;
    count++;

    // Step 3: Add remaining intervals
    while (i < intervalsSize) {

        result[count] = malloc(2 * sizeof(int));

        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];

        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    *returnSize = count;

    return result;
}
