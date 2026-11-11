/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int result[40320][8];
int count = 0;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void backtrack(int *nums, int numsSize, int *temp,
               int depth, int *used)
{
    if (depth == numsSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            result[count][i] = temp[i];
        }

        count++;
        return;
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (used[i])
            continue;

        // Skip duplicate elements
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        temp[depth] = nums[i];
        used[i] = 1;

        backtrack(nums, numsSize, temp, depth + 1, used);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize, int** returnColumnSizes)
{
    count = 0;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int temp[8];
    int used[8] = {0};

    backtrack(nums, numsSize, temp, 0, used);

    int **answer = malloc(count * sizeof(int *));
    *returnColumnSizes = malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        answer[i] = malloc(numsSize * sizeof(int));

        for (int j = 0; j < numsSize; j++)
        {
            answer[i][j] = result[i][j];
        }

        (*returnColumnSizes)[i] = numsSize;
    }

    *returnSize = count;

    return answer;
}
