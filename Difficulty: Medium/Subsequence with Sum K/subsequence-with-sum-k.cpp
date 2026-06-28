class Solution {
public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        vector<bool> dp(k + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int sum = k; sum >= num; sum--) {
                dp[sum] = dp[sum] || dp[sum - num];
            }
        }

        return dp[k];
    }
};