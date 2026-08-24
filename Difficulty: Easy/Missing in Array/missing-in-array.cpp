class Solution {
public:
    int missingNum(vector<int>& arr) {
        int n = arr.size();

        vector<int> freq(n + 2, 0);

        for (int i = 0; i < n; i++) {
            freq[arr[i]] = 1;
        }

        for (int i = 1; i <= n + 1; i++) {
            if (freq[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};