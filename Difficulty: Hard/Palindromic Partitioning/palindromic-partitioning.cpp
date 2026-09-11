class Solution {
public:
    int palPartition(string &s) {
        int n = s.length();
        vector<int> dp(n);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            int minCut = i;

            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;

                    if (j == 0) {
                        minCut = 0;
                    } else {
                        minCut = min(minCut, dp[j - 1] + 1);
                    }
                }
            }
            dp[i] = minCut;
        }

        return dp[n - 1];
    }
};