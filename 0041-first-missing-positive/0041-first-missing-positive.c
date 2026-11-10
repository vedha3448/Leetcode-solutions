
int firstMissingPositive(int* nums, int numsSize) {

    int i = 0;

    // Place each number at its correct index
    while (i < numsSize) {

        if (nums[i] > 0 &&
            nums[i] <= numsSize &&
            nums[nums[i] - 1] != nums[i]) {

            int correctIndex = nums[i] - 1;

            // Swap numbers
            int temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;

        } else {
            i++;
        }
    }

    // Find the first missing positive number
    for (int i = 0; i < numsSize; i++) {

        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return numsSize + 1;
}
