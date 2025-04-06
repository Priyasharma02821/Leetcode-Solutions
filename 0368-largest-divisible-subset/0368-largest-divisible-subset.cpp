class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1); // dp[i] = size of the largest subset ending at nums[i]
    vector<int> prev(n, -1); // prev[i] = index of previous element in the subset

    int maxIndex = 0; // index of the last element of the largest subset

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> result;
    while (maxIndex >= 0) {
        result.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}
};