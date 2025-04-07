class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums)
        totalSum += num;

    // If total sum is odd, we cannot partition it into two equal subsets
    if (totalSum % 2 != 0)
        return false;

    int target = totalSum / 2;
    int n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}
};