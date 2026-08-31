class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();

        int max_1s = 0;
        int max_row_index = -1;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int first_1_idx = m; 

            
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[i][mid] == 1) {
                    first_1_idx = mid;
                    high = mid - 1;   
                } else {
                    low = mid + 1;     
                }
            }
            int current_1s = m - first_1_idx;

            if (current_1s > max_1s) {
                max_1s = current_1s;
                max_row_index = i;
            }
        }

        return max_row_index;
    }
};