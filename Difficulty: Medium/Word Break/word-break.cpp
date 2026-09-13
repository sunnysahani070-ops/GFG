class Solution {
public:
    bool wordBreak(string& s, vector<string>& dictionary) {
        unordered_set<string> word_set;
        int max_len = 0;

        for (const string& word : dictionary) {
            word_set.insert(word);
            max_len = max(max_len, (int)word.length());
        }

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j >= max(0, i - max_len); --j) {
                if (dp[j]) {
                    if (word_set.find(s.substr(j, i - j)) != word_set.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};