#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    set<string> getLCS(int i, int j, const string &s1, const string &s2, 
                       const vector<vector<int>> &dp, 
                       vector<vector<set<string>>> &memo, 
                       vector<vector<bool>> &visited) {
        if (i == 0 || j == 0) {
            return {""};
        }
        if (visited[i][j]) {
            return memo[i][j];
        }

        set<string> result;
        if (s1[i - 1] == s2[j - 1]) {
            set<string> prev = getLCS(i - 1, j - 1, s1, s2, dp, memo, visited);
            for (const string &sub : prev) {
                result.insert(sub + s1[i - 1]);
            }
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                set<string> left = getLCS(i - 1, j, s1, s2, dp, memo, visited);
                result.insert(left.begin(), left.end());
            }
            if (dp[i][j - 1] == dp[i][j]) {
                set<string> right = getLCS(i, j - 1, s1, s2, dp, memo, visited);
                result.insert(right.begin(), right.end());
            }
        }

        visited[i][j] = true;
        memo[i][j] = result;
        return result;
    }

public:
    vector<string> allLCS(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // 1. Fill DP Table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // If no common subsequence exists
        if (dp[n][m] == 0) return {""};

        // 2. Memoized Backtracking
        vector<vector<set<string>>> memo(n + 1, vector<set<string>>(m + 1));
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

        set<string> final_result = getLCS(n, m, s1, s2, dp, memo, visited);

        return vector<string>(final_result.begin(), final_result.end());
    }
};