class Solution {
private:
    vector<int> bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        
        vector<int> component;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            component.push_back(node);
            
            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return component;
    }

public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        vector<vector<int>> ans;
        
        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                ans.push_back(bfs(i, adj, vis));
            }
        }
        
        return ans;
    }
};