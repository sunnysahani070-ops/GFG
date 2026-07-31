#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int longestBitonicSequence(int n, std::vector<int>& nums) {
        if (n < 3) return 0;

        std::vector<int> dp1(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < i; ++prev) {
                if (nums[prev] < nums[i] && dp1[prev] + 1 > dp1[i]) {
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }

        
        std::vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int next = i + 1; next < n; ++next) {
                if (nums[next] < nums[i] && dp2[next] + 1 > dp2[i]) {
                    dp2[i] = dp2[next] + 1;
                }
            }
        }

        int maxLen = 0;

       
        for (int i = 0; i < n; ++i) {
            
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxLen = std::max(maxLen, dp1[i] + dp2[i] - 1);
            }
        }

        return maxLen;
    }
};