class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<int> dp(capacity + 1, 0);

        
        for (int w = 1; w <= capacity; ++w) {
            for (int i = 0; i < n; ++i) {
                if (wt[i] <= w) {
                    dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
                }
            }
        }

        return dp[capacity];
    }
};