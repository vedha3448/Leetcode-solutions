/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

unsigned long hash(char *str) {
    unsigned long h = 5381;

    while (*str) {
        h = h * 33 + *str;
        str++;
    }

    return h;
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    int capacity = 1;

    while (capacity < strsSize * 2)
        capacity *= 2;

    char **keys = calloc(capacity, sizeof(char *));
    int *groupIndex = malloc(capacity * sizeof(int));

    char ***result = malloc(strsSize * sizeof(char **));
    *returnColumnSizes = calloc(strsSize, sizeof(int));

    *returnSize = 0;

    for (int i = 0; i < strsSize; i++) {

        int len = strlen(strs[i]);

        char *key = malloc(len + 1);
        strcpy(key, strs[i]);

        qsort(key, len, sizeof(char), compare);

        unsigned long h = hash(key) % capacity;

        while (keys[h] != NULL && strcmp(keys[h], key) != 0) {
            h = (h + 1) % capacity;
        }

        int g;

        if (keys[h] == NULL) {

            keys[h] = key;
            g = (*returnSize)++;

            groupIndex[h] = g;

            result[g] = malloc(strsSize * sizeof(char *));
        }
        else {
            free(key);
            g = groupIndex[h];
        }

        result[g][(*returnColumnSizes)[g]++] = strs[i];
    }

    for (int i = 0; i < capacity; i++)
        free(keys[i]);

    free(keys);
    free(groupIndex);

    return result;
}
