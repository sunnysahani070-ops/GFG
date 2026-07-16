#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string findOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;

        // Step 1: Initialize in-degree to 0 for all unique characters
        for (const string& word : words) {
            for (char c : word) {
                inDegree[c] = 0;
            }
        }

        // Step 2: Build the directed graph and calculate in-degrees
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool diffFound = false;
            
            for (int j = 0; j < len; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].push_back(w2[j]);
                    inDegree[w2[j]]++;
                    diffFound = true;
                    break; 
                }
            }
            
            // Invalid case: e.g., w1="abcd", w2="abc" -> longer word before shorter prefix
            if (!diffFound && w1.length() > w2.length()) {
                return "";
            }
        }

        // Step 3: Topological Sort using Kahn's Algorithm (BFS)
        queue<char> q;
        for (auto const& [node, degree] : inDegree) {
            if (degree == 0) {
                q.push(node);
            }
        }

        string result = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Cycle detection
        // If result doesn't contain all unique characters, there is a cycle
        if (result.length() == inDegree.size()) {
            return result;
        }
        
        return "";
    }
};