/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

    int* result = malloc(2 * sizeof(int));

    *returnSize = 2;

    result[0] = -1;
    result[1] = -1;

    int left = 0;
    int right = numsSize - 1;

    // Find first occurrence
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[0] = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    left = 0;
    right = numsSize - 1;

    // Find last occurrence
    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            result[1] = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return result;
}
