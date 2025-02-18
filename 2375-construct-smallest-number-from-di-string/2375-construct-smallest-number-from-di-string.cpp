class Solution {
public:
    string smallestNumber(string pattern) {
        string result;

        // Iterate through the pattern and build the result
        for (int currentIndex = 0, previousIndex = 0;
             currentIndex <= pattern.length(); ++currentIndex) {
            result += to_string(1 + currentIndex);

            // Reverse the substring starting from previousIndex when necessary
            if (currentIndex == pattern.length() ||
                pattern[currentIndex] == 'I') {
                reverse(result.begin() + previousIndex, result.end());
                previousIndex = currentIndex + 1;
            }
        }

        return result;
    }
};