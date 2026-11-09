
char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j;

    for (i = 0; strs[0][i] != '\0'; i++) {

        char current = strs[0][i];

        for (j = 1; j < strsSize; j++) {

            if (strs[j][i] != current) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }

    return strs[0];
}
