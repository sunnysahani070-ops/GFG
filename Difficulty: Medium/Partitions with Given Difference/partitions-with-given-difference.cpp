#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        
        if (total < diff || (total - diff) % 2 != 0) {
            return 0;
        }
        
        int target = (total - diff) / 2;
        
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1; 
        
        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        
        return dp[target];
    }
};