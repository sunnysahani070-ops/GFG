class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {

        int n = mat.size();

        for (int i = 0; i < n; i++) {

            bool flag = true;

          
            for (int j = 0; j < n; j++) {
                if (j != i && mat[j][i] == 0) {
                    flag = false;
                    break;
                }
            }

            if (!flag) continue;

            for (int j = 0; j < n; j++) {
                if (j != i && mat[i][j] == 1) {
                    flag = false;
                    break;
                }
            }

            if (flag) return i;
        }

        return -1;
    }
};