class Solution {
    int solve(int i, vector<int>& height, vector<int>& dp) {
        
        if (i == 0) return 0;
        
        
        if (dp[i] != -1) return dp[i];
        
        
        int jumpOne = solve(i - 1, height, dp) + abs(height[i] - height[i - 1]);
        
        
        int jumpTwo = INT_MAX;
        if (i > 1) {
            jumpTwo = solve(i - 2, height, dp) + abs(height[i] - height[i - 2]);
        }
        
        
        return dp[i] = min(jumpOne, jumpTwo);
    }

public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp);
    }
};