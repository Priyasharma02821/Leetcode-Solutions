class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, pair<int, int>> pos;
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                pos[mat[i][j]] = {i, j};
        
        vector<int> rCnt(row, 0);
        vector<int> cCnt(col, 0);
        
        for(int i = 0; i < arr.size(); i++) {
            auto [r, c] = pos[arr[i]];
            rCnt[r]++;
            cCnt[c]++;
            if(rCnt[r] == col || cCnt[c] == row)
                return i;
        }
        return arr.size() - 1;
    }
};