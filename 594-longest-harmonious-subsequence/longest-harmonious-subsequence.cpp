class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int longest = 0;
        for (int num : nums) {
            hash[num]++;
        }
        for (auto& pair : hash) {
            int key = pair.first;
            if (hash.count(key + 1)) {
                longest = max(longest, hash[key] + hash[key + 1]);
            }
        }
        return longest;
    }
};