class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        vector<int> temp(arr, arr + n);
        sort(temp.begin(), temp.end());

        unordered_map<int, queue<int>> mp;

        // Store all sorted indices of every value
        for (int i = 0; i < n; i++) {
            mp[temp[i]].push(i);
        }

        // Check displacement
        for (int i = 0; i < n; i++) {
            int sortedIndex = mp[arr[i]].front();
            mp[arr[i]].pop();

            if (abs(i - sortedIndex) > k)
                return "No";
        }

        return "Yes";
    }
};