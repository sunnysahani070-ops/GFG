#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Solution {
private:
    // Helper function to perform DFS and find Topological Sort
    void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                topoSort(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Create Adjacency List: node -> {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Step 2: Find Topological Sort
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(i, adj, visited, st);
            }
        }

        // Step 3: Initialize distances with infinity
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // Source is always 0

        // Step 4: Relax the edges in topological order
        while (!st.empty()) {
            int u = st.top();
            st.pop();

            // If the node has been reached from the source
            if (dist[u] != INT_MAX) {
                for (auto& edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Step 5: Replace INT_MAX with -1 for unreachable vertices
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};