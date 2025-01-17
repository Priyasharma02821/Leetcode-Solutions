class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    vector<int> original(n);
    original[0] = 0;
    for (int i = 1; i < n; i++) {
        original[i] = derived[i - 1] ^ original[i - 1];
    }
    if ((original[0] ^ original[n - 1]) == derived[n - 1]) {
        return true;
    }
    original[0] = 1;
    for (int i = 1; i < n; i++) {
        original[i] = derived[i - 1] ^ original[i - 1];
    }
    if ((original[0] ^ original[n - 1]) == derived[n - 1]) {
        return true;
    }
    
    return false;
}
};