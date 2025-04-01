class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            int next = i + questions[i][1] + 1; // Index after cooldown
            long long take = questions[i][0] + (next < n ? dp[next] : 0);
            long long skip = dp[i + 1];
            dp[i] = max(take, skip);
        }
        
        return dp[0];
    }
};