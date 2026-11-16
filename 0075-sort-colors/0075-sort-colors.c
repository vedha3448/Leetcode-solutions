
void sortColors(int* nums, int numsSize) {
    int low = 0;
    int mid = 0;
    int high = numsSize - 1;

    while (mid <= high) {

        if (nums[mid] == 0) {
            // Swap 0 with the element at low
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            low++;
            mid++;
        }

        else if (nums[mid] == 1) {
            // 1 is already in the correct region
            mid++;
        }

        else {
            // Swap 2 with the element at high
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }
}
