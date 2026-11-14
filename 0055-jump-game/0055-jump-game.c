
bool canJump(int* nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {

        // If current index is unreachable
        if (i > maxReach) {
            return false;
        }

        // Update maximum reachable index
        if (i + nums[i] > maxReach) {
            maxReach = i + nums[i];
        }

        // If we can reach the last index
        if (maxReach >= numsSize - 1) {
            return true;
        }
    }

    return true;
}
