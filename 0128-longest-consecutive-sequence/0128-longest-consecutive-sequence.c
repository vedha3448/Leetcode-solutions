
#include <stdlib.h>
#include <stdint.h>

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    uint32_t *a = malloc(numsSize * sizeof(uint32_t));
    uint32_t *b = malloc(numsSize * sizeof(uint32_t));

    if (a == NULL || b == NULL) {
        free(a);
        free(b);
        return 0;
    }

    // Convert signed integers to sortable unsigned values
    for (int i = 0; i < numsSize; i++) {
        a[i] = ((uint32_t)nums[i]) ^ 0x80000000U;
    }

    // Radix sort: 4 passes, 8 bits per pass
    for (int shift = 0; shift < 32; shift += 8) {
        int count[256] = {0};

        for (int i = 0; i < numsSize; i++) {
            count[(a[i] >> shift) & 255]++;
        }

        int sum = 0;

        for (int i = 0; i < 256; i++) {
            int temp = count[i];
            count[i] = sum;
            sum += temp;
        }

        for (int i = 0; i < numsSize; i++) {
            int index = (a[i] >> shift) & 255;
            b[count[index]++] = a[i];
        }

        uint32_t *temp = a;
        a = b;
        b = temp;
    }

    int longest = 1;
    int current = 1;

    for (int i = 1; i < numsSize; i++) {
        if (a[i] == a[i - 1])
            continue;

        if (a[i] - a[i - 1] == 1) {
            current++;
        } else {
            current = 1;
        }

        if (current > longest)
            longest = current;
    }

    free(a);
    free(b);

    return longest;
}
