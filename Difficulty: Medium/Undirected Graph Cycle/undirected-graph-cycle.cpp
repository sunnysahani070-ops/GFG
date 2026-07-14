class Solution {
public:
    // Helper BFS function that returns true if a cycle is found in the current component
    bool bfsCheckCycle(int start, int V, vector<vector<int>> &adj, vector<int> &vis) {
        // Queue stores pairs of {current_node, parent_node}
        queue<pair<int, int>> q; 
        
        vis[start] = 1;
        q.push({start, -1}); // Start node has no parent (-1)

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                } 
                // If the neighbor is visited and is NOT the parent, a cycle exists!
                else if (neighbor != parent) {
                    return true; 
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>> &edges) {
        // 1. Build the correct Adjacency List using V
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Because it's an undirected graph
        }

        // 2. Globally track visited nodes across all components
        vector<int> vis(V, 0);

        // 3. Loop through all vertices to handle disconnected graph components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfsCheckCycle(i, V, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};