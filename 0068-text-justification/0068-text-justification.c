/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {

    char** result = (char**)malloc(wordsSize * sizeof(char*));

    int index = 0;
    int i = 0;

    while (i < wordsSize) {

        int j = i;
        int totalLength = 0;

        // Find maximum words that can fit in one line
        while (j < wordsSize &&
               totalLength + strlen(words[j]) + (j - i) <= maxWidth) {

            totalLength += strlen(words[j]);
            j++;
        }

        int wordCount = j - i;
        int spaces = maxWidth - totalLength;

        char* line = (char*)malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;

        // Last line or line containing only one word
        if (j == wordsSize || wordCount == 1) {

            for (int k = i; k < j; k++) {

                int len = strlen(words[k]);

                for (int x = 0; x < len; x++) {
                    line[pos++] = words[k][x];
                }

                if (k < j - 1) {
                    line[pos++] = ' ';
                }
            }

            // Add remaining spaces at the end
            while (pos < maxWidth) {
                line[pos++] = ' ';
            }
        }

        else {

            int gaps = wordCount - 1;
            int spaceEach = spaces / gaps;
            int extraSpaces = spaces % gaps;

            for (int k = i; k < j; k++) {

                int len = strlen(words[k]);

                for (int x = 0; x < len; x++) {
                    line[pos++] = words[k][x];
                }

                if (k < j - 1) {

                    int count = spaceEach;

                    if (k - i < extraSpaces) {
                        count++;
                    }

                    for (int s = 0; s < count; s++) {
                        line[pos++] = ' ';
                    }
                }
            }
        }

        line[pos] = '\0';

        result[index++] = line;

        i = j;
    }

    *returnSize = index;

    return result;
}
