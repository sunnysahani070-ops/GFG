class Solution {
public:
    int cutRod(vector<int>& price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        
        
        for (int i = 1; i <= n; i++) {
            int max_val = INT_MIN;
            for (int j = 1; j <= i; j++) {
                max_val = max(max_val, price[j - 1] + dp[i - j]);
            }
            dp[i] = max_val;
        }
        
        return dp[n];
    }
};