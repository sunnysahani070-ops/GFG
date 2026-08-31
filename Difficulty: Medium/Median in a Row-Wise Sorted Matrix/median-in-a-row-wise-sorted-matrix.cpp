class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 1;
        int high = 2000;   

        while (low < high) {
            int mid = low + (high - low) / 2;

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (cnt <= (n * m) / 2)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};