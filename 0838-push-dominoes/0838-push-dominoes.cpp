class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        
        // Left to right pass to find the nearest R to the left
        int nearestR = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                nearestR = i;
            } else if (dominoes[i] == 'L') {
                nearestR = -1;
            } else if (nearestR != -1) {
                right[i] = i - nearestR;
            }
        }
        
        // Right to left pass to find the nearest L to the right
        int nearestL = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                nearestL = i;
            } else if (dominoes[i] == 'R') {
                nearestL = -1;
            } else if (nearestL != -1) {
                left[i] = nearestL - i;
            }
        }
        
        // Determine the final state
        string result;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                result += dominoes[i];
            } else {
                if (left[i] < right[i]) {
                    result += 'L';
                } else if (right[i] < left[i]) {
                    result += 'R';
                } else {
                    result += '.';
                }
            }
        }
        
        return result;
    }
};