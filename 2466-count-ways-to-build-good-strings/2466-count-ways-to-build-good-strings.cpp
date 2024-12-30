class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;

    // DP array to store the number of ways to form strings of length i
    vector<int> dp(high + 1, 0);
    dp[0] = 1; // Base case: 1 way to form an empty string

    // Fill the DP array
    for (int i = 1; i <= high; ++i) {
        if (i >= zero) {
            dp[i] = (dp[i] + dp[i - zero]) % MOD;
        }
        if (i >= one) {
            dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
    }

    // Sum up the counts for lengths in the range [low, high]
    int result = 0;
    for (int i = low; i <= high; ++i) {
        result = (result + dp[i]) % MOD;
    }

    return result;
    }
};