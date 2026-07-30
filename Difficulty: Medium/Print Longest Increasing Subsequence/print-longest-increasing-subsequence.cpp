class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> dp(n, 1);
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev] && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    parent[i] = prev;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            } else if (dp[i] == maxLength) {
            }
        }
        vector<int> lis;
        int curr = lastIndex;
        while (parent[curr] != curr) {
            lis.push_back(arr[curr]);
            curr = parent[curr];
        }
        lis.push_back(arr[curr]);
        
        reverse(lis.begin(), lis.end());
        return lis;
    }
};