
int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int minSum = 1000000000;

    for (int i = 0; i < numsSize; i++) {
        int sum = 0;

        for (int j = i; j < numsSize && j < i + r; j++) {
            sum += nums[j];

            int length = j - i + 1;

            if (length >= l && length <= r && sum > 0) {
                if (sum < minSum) {
                    minSum = sum;
                }
            }
        }
    }

    return (minSum == 1000000000) ? -1 : minSum;
}
    
