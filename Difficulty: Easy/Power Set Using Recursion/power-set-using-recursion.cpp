class Solution {
    void powerset(string curr, string &s, int i, int n,
                  vector<string> &ans) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        // Take s[i]
        powerset(curr + s[i], s, i + 1, n, ans);

        // Don't take s[i]
        powerset(curr, s, i + 1, n, ans);
    }

public:
    vector<string> powerSet(string s) {
        vector<string> ans;
        powerset("", s, 0, s.size(), ans);
        return ans;
    }
};