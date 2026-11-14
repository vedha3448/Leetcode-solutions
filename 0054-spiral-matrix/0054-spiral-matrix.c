

/**
 * Note: The returned array must be malloced.
 * The caller will free it.
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int m = matrixSize;
    int n = matrixColSize[0];

    int *result = (int*)malloc(m * n * sizeof(int));

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    int k = 0;

    while (top <= bottom && left <= right) {

        // 1. Traverse left to right
        for (int i = left; i <= right; i++) {
            result[k++] = matrix[top][i];
        }
        top++;

        // 2. Traverse top to bottom
        for (int i = top; i <= bottom; i++) {
            result[k++] = matrix[i][right];
        }
        right--;

        // 3. Traverse right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[k++] = matrix[bottom][i];
            }
            bottom--;
        }

        // 4. Traverse bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = k;
    return result;
}