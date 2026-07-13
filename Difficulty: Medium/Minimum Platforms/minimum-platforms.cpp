class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int minp = 0;
        int mint = 0;
        int i = 0;
        int j = 0;

        while (i < arr.size() && j < dep.size()) {
            if (arr[i] <= dep[j]) {
                mint++;
                i++;
            } else {
                mint--;
                j++;
            }
            minp = max(minp, mint);
        }

        return minp;
    }
};