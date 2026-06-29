class Solution {
    void solve(vector<vector<int>>& m, int n, int i, int j,
               vector<string>& ans, string path,
               vector<vector<int>>& vis) {

        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[i][j] = 1;

        // Down
        if (i + 1 < n && m[i + 1][j] == 1 && !vis[i + 1][j])
            solve(m, n, i + 1, j, ans, path + 'D', vis);

        // Left
        if (j - 1 >= 0 && m[i][j - 1] == 1 && !vis[i][j - 1])
            solve(m, n, i, j - 1, ans, path + 'L', vis);

        // Right
        if (j + 1 < n && m[i][j + 1] == 1 && !vis[i][j + 1])
            solve(m, n, i, j + 1, ans, path + 'R', vis);

        // Up
        if (i - 1 >= 0 && m[i - 1][j] == 1 && !vis[i - 1][j])
            solve(m, n, i - 1, j, ans, path + 'U', vis);

        vis[i][j] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<string> ans;

        if (mat[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(mat, n, 0, 0, ans, "", vis);

        return ans;
    }
};