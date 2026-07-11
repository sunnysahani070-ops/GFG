class Solution {
public:
    void replaceWithRank(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({arr[i], i}); // {value, original index}
        }

        sort(temp.begin(), temp.end());

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[temp[i].second] = i;
        }

        arr = ans;
    }
};
