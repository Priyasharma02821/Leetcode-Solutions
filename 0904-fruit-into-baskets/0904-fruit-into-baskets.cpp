class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int n = fruits.size();
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> basket;

    while (r < n) {
        basket[fruits[r]]++;
        while (basket.size() > 2) {
            basket[fruits[l]]--;
            if (basket[fruits[l]] == 0) {
                basket.erase(fruits[l]);
            }
            l++; 
        }
        maxlen = max(maxlen, r - l + 1);
        r++; 
    }
    return maxlen;
    }
};