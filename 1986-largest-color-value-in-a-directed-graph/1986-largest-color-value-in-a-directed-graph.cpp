class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<vector<int>> colorCounts(n, vector<int>(26, 0));
    int processedNodes = 0;
    int maxColorValue = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        processedNodes++;
        
        colorCounts[u][colors[u] - 'a']++;
        maxColorValue = max(maxColorValue, colorCounts[u][colors[u] - 'a']);
        
        for (int v : adj[u]) {
            for (int c = 0; c < 26; ++c) {
                colorCounts[v][c] = max(colorCounts[v][c], colorCounts[u][c]);
            }
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (processedNodes != n) {
        return -1;
    }
    
    return maxColorValue;
}
};