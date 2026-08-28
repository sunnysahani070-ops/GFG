class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        int i = 0;
        int j = arr.size() - 1;
        int ans = -1;

        while (i <= j) {
            int k = i + (j - i) / 2;

           
            if (arr[k] <= x) {
                ans = k;
                i = k + 1;
            } else {
                j = k - 1;
            }
        }

        return ans;
    }
};