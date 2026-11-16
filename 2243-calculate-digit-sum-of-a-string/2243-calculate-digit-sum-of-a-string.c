
char* digitSum(char* s, int k) {
    while (strlen(s) > k) {
        char temp[205];
        int index = 0;

        int len = strlen(s);

        for (int i = 0; i < len; i += k) {
            int sum = 0;

            // Calculate sum of digits in each group
            for (int j = i; j < i + k && j < len; j++) {
                sum += s[j] - '0';
            }

            // Convert sum into string
            char buffer[10];
            sprintf(buffer, "%d", sum);

            // Append sum to new string
            for (int j = 0; buffer[j] != '\0'; j++) {
                temp[index++] = buffer[j];
            }
        }

        temp[index] = '\0';
        strcpy(s, temp);
    }

    return s;
}
