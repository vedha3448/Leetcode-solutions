/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int result[720][6];
int count;

void backtrack(int *nums, int numsSize, int *temp, int depth, int *used)
{
    // Base case: permutation is complete
    if (depth == numsSize)
    {
        for (int i = 0; i < numsSize; i++)
        {
            result[count][i] = temp[i];
        }

        count++;
        return;
    }

    // Try every unused element
    for (int i = 0; i < numsSize; i++)
    {
        if (!used[i])
        {
            temp[depth] = nums[i];
            used[i] = 1;

            backtrack(nums, numsSize, temp, depth + 1, used);

            // Backtracking
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes)
{
    count = 0;

    int temp[6];
    int used[6] = {0};

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
