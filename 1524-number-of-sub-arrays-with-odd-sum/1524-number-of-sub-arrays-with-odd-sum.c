
int numOfSubarrays(int* arr, int arrSize) {
    const int MOD = 1000000007;

    long long odd = 0;
    long long even = 1;
    long long ans = 0;

    int prefixSum = 0;

    for (int i = 0; i < arrSize; i++) {
        prefixSum += arr[i];

        if (prefixSum % 2 == 0) {
            ans = (ans + odd) % MOD;
            even++;
        } 
        else {
            ans = (ans + even) % MOD;
            odd++;
        }
    }

    return (int)ans;
}
