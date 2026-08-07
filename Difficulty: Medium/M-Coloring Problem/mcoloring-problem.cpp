#include <vector>

using namespace std;

class Solution {
private:
    bool isSafe(int node, vector<int>& color, vector<vector<int>>& adj, int col) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int v, vector<int>& color, vector<vector<int>>& adj, int m) {
        if (node == v) {
            return true;
        }

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, adj, col)) {
                color[node] = col;
                
                if (solve(node + 1, v, color, adj, m)) {
                    return true;
                }
                
                color[node] = 0; // Backtrack
            }
        }

        return false;
    }

public:
    bool graphColoring(int v, vector<vector<int>>& edges, int m) {
        // Build adjacency list representation from edge list
        vector<vector<int>> adj(v);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(v, 0); // Stores assigned color for each node (0 means uncolored)
        
        return solve(0, v, color, adj, m);
    }
};