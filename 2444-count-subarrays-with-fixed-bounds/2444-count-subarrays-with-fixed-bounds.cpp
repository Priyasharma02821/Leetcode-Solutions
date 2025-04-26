class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
      long long res = 0;
    int start = 0;
    int lastMin = -1, lastMax = -1;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < minK || nums[i] > maxK) {
            start = i + 1;
            lastMin = -1;
            lastMax = -1;
            continue;
        }
        
        if (nums[i] == minK) {
            lastMin = i;
        }
        if (nums[i] == maxK) {
            lastMax = i;
        }
        
        if (lastMin != -1 && lastMax != -1) {
            res += max(0, min(lastMin, lastMax) - start + 1);
        }
    }
    
    return res;  
    }
};