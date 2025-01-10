class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> h;

    while (r < n) {
        if (h.find(s[r]) != h.end() && h[s[r]] >= l) { 
            l = h[s[r]] + 1;
        }
        h[s[r]] = r; 
        maxlen = max(maxlen, r - l + 1);
        r++; 
    }

    return maxlen;
    }
};