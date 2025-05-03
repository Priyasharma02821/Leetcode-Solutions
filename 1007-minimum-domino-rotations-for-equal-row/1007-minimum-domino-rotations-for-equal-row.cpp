class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
    if (n == 0) return -1;
    
    // The possible target values are the first top or bottom
    int target1 = tops[0];
    int target2 = bottoms[0];
    
    int result = INT_MAX;
    
    // Check for target1
    int top_rotations = 0, bottom_rotations = 0;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (tops[i] != target1 && bottoms[i] != target1) {
            possible = false;
            break;
        }
        if (tops[i] != target1) {
            top_rotations++;
        }
        if (bottoms[i] != target1) {
            bottom_rotations++;
        }
    }
    if (possible) {
        result = min(top_rotations, bottom_rotations);
    }
    
    // Check for target2
    top_rotations = 0;
    bottom_rotations = 0;
    possible = true;
    for (int i = 0; i < n; ++i) {
        if (tops[i] != target2 && bottoms[i] != target2) {
            possible = false;
            break;
        }
        if (tops[i] != target2) {
            top_rotations++;
        }
        if (bottoms[i] != target2) {
            bottom_rotations++;
        }
    }
    if (possible) {
        result = min(result, min(top_rotations, bottom_rotations));
    }
    
    return result == INT_MAX ? -1 : result;
    }
};