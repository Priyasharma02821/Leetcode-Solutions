class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            vector<int> lps = computeLPSArray(words[currentWordIndex]);
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex], lps)) {
                    matchingWords.push_back(words[currentWordIndex]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Function to compute the LPS (Longest Prefix Suffix) array for the
    // substring `sub`.
    vector<int> computeLPSArray(string &sub) {
        vector<int> lps(sub.size(), 0);  // Initialize the LPS array with 0.
        int currentIndex = 1;            // Start from the second character.
        // Length of the current longest prefix which is also a suffix.
        int len = 0;

        while (currentIndex < sub.size()) {
            if (sub[currentIndex] == sub[len]) {
                len++;  // If the current characters match, extend the prefix.
                lps[currentIndex] = len;  // Store the length of the prefix.
                currentIndex++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];  // Backtrack using LPS array to find a
                                         // shorter match.
                } else {
                    currentIndex++;
                }
            }
        }
        return lps;
    }

    // Function to check if `sub` is a substring of `main` using the KMP
    // algorithm.
    bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
        int mainIndex = 0;  // Pointer for `main`.
        int subIndex = 0;   // Pointer for `sub`.

        while (mainIndex < main.size()) {
            if (main[mainIndex] == sub[subIndex]) {
                subIndex++;
                mainIndex++;
                if (subIndex == sub.size()) return true;  // Found a match.
            } else {
                if (subIndex > 0) {
                    // Use the LPS to skip unnecessary comparisons.
                    subIndex = lps[subIndex - 1];
                } else {
                    mainIndex++;
                }
            }
        }
        return false;  // No match found.
    }
};