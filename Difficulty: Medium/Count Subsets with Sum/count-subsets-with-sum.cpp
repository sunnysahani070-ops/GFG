class Solution {
    int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx < 0) {
            return (target == 0) ? 1 : 0;
        }
        
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        // Exclude the current element
        int not_take = solve(idx - 1, target, arr, dp);
        
        // Include the current element if it doesn't exceed the target
        int take = 0;
        if (arr[idx] <= target) {
            take = solve(idx - 1, target - arr[idx], arr, dp);
        }
        
        return dp[idx][target] = take + not_take;
    }

public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        // dp[idx][target] initialized to -1
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, arr, dp);
    }
};