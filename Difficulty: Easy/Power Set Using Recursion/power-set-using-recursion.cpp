class Solution {
public:
    vector<string> powerSet(string s) {
        int n = s.length();
        int totalSets = 1 << n;
        vector<string> ans;
        for (int i = 0; i < totalSets; i++) {
            string curr = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    curr += s[j];
                }
            }
            ans.push_back(curr);
        }

        return ans;
    }
};