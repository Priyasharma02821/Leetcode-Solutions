class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    int target = n * n;
    
    // Function to convert square number to board coordinates
    auto getPos = [n](int square) -> pair<int, int> {
        int row = (square - 1) / n;
        int col = (square - 1) % n;
        if (row % 2 == 1) { // Boustrophedon style (alternating direction)
            col = n - 1 - col;
        }
        row = n - 1 - row; // Convert to 0-indexed from bottom
        return {row, col};
    };
    
    queue<pair<int, int>> q; // {square, moves}
    unordered_set<int> visited;
    q.push({1, 0});
    visited.insert(1);
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int square = current.first;
        int moves = current.second;
        
        if (square == target) {
            return moves;
        }
        
        // Explore all possible next moves (1-6)
        for (int i = 1; i <= 6; i++) {
            int next_square = square + i;
            if (next_square > target) break;
            
            // Get board coordinates
            auto pos = getPos(next_square);
            int row = pos.first, col = pos.second;
            
            // Check for snake or ladder
            if (board[row][col] != -1) {
                next_square = board[row][col];
            }
            
            if (visited.find(next_square) == visited.end()) {
                visited.insert(next_square);
                q.push({next_square, moves + 1});
            }
        }
    }
    
    return -1; // Target not reachable
}
};