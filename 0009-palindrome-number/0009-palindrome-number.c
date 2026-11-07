
bool isPalindrome(int x) {
    int original = x;
    long long reversed = 0;

    // Negative numbers are not palindromes
    if (x < 0) {
        return false;
    }

    // Reverse the number
    while (x > 0) {
        int digit = x % 10;

        reversed = reversed * 10 + digit;

        x = x / 10;
    }

    // Compare original and reversed numbers
    if (original == reversed) {
        return true;
    }

    return false;
}
