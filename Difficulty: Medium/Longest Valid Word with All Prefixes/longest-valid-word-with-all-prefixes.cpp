#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        string longestWord = "";
        
        for (const string& word : words) {
            bool isValid = true;
            string currentPrefix = "";
            
            // Check all prefixes of the current word
            for (int i = 0; i < word.length() - 1; ++i) {
                currentPrefix += word[i];
                if (wordSet.find(currentPrefix) == wordSet.end()) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                // If it's longer, or same length but lexicographically smaller
                if (word.length() > longestWord.length() || 
                    (word.length() == longestWord.length() && word < longestWord)) {
                    longestWord = word;
                }
            }
        }
        
        return longestWord;
    }
};