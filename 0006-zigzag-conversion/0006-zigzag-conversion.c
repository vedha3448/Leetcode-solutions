
char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        return s;
    }

    char *result = (char *)malloc((len + 1) * sizeof(char));

    int index = 0;

    for (int row = 0; row < numRows; row++) {

        int pos = row;
        int goingDown = 1;

        while (pos < len) {
            result[index++] = s[pos];

            if (row == 0 || row == numRows - 1) {
                pos += 2 * (numRows - 1);
            }
            else {
                if (goingDown) {
                    pos += 2 * (numRows - row - 1);
                }
                else {
                    pos += 2 * row;
                }

                goingDown = !goingDown;
            }
        }
    }

    result[index] = '\0';

    return result;
}
