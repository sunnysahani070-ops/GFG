class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        
        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int curr_dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (curr_dis > dis[node]) continue;

            for (auto& it : adj[node]) {
                int neighbor = it.first;
                int edgeweight = it.second;

                if (curr_dis + edgeweight < dis[neighbor]) {
                    dis[neighbor] = curr_dis + edgeweight;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        return dis;
    }
};