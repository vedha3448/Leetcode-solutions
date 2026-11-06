double findMedianSortedArrays(int nums1[],int m, int nums2[],int n)
{
    
    // Always perform binary search on the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int low = 0, high = m;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            
            if ((m + n) % 2 == 1) {
                return (double)(
                    (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2
                );
            }

            int leftMax = (maxLeft1 > maxLeft2) ? maxLeft1 : maxLeft2;
            int rightMin = (minRight1 < minRight2) ? minRight1 : minRight2;

            return ((double)leftMax + rightMin) / 2.0;
        }
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        }
        else {
            low = partition1 + 1;
        }
    }

    return 0.0;
}

