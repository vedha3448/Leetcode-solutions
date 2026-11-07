
int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long long result = 0;

    // Step 1: Ignore leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // Step 2: Check the sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    }
    else if (s[i] == '+') {
        sign = 1;
        i++;
    }

    // Step 3: Convert digits into integer
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        result = result * 10 + digit;

        // Step 4: Check 32-bit integer overflow
        if (sign == 1 && result > 2147483647) {
            return 2147483647;
        }

        if (sign == -1 && result > 2147483648LL) {
            return -2147483647 - 1;
        }

        i++;
    }

    return (int)(result * sign);
}