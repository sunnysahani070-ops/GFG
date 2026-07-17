#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Initialize distances to -1 (unvisited)
        vector<int> dist(V, -1);
        queue<int> q;

        // Start BFS
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == dest) return dist[u];

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return dist[dest];
    }
};