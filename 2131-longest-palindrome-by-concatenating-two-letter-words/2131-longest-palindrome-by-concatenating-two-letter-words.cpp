class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        
        int length = 0;
        bool has_central = false;
        
        for (auto& entry : freq) {
            string word = entry.first;
            string reversed_word = string(1, word[1]) + string(1, word[0]);
            
            if (word == reversed_word) {
                int count = entry.second;
                length += (count / 2) * 4;
                if (count % 2 == 1) {
                    has_central = true;
                }
            } else {
                if (freq.find(reversed_word) != freq.end()) {
                    int min_pairs = min(entry.second, freq[reversed_word]);
                    // To avoid double counting, we only process when word < reversed_word
                    if (word < reversed_word) {
                        length += min_pairs * 4;
                    }
                }
            }
        }
        
        if (has_central) {
            length += 2;
        }
        
        return length;   
    }
};