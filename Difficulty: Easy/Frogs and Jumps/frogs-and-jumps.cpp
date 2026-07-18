class Solution {
  public:
    int unvisitedLeaves(vector<int>& arr, int k) {
        int n = arr.size(); // Derive n from the vector itself
        
        // Boolean array to track visited leaves. 
        // Index 0 is ignored, leaves are 1 to k.
        vector<bool> visited(k + 1, false);
        
        // Track unique strengths to avoid redundant work
        vector<bool> strengthUsed(k + 1, false);
        
        for (int i = 0; i < n; i++) {
            int s = arr[i];
            
            // If frog strength is greater than k, it jumps over the pond entirely
            if (s > k) continue;
            
            // If we already processed this strength, skip it
            if (strengthUsed[s]) continue;
            
            // Mark all multiples of s as visited
            for (int j = s; j <= k; j += s) {
                visited[j] = true;
            }
            
            // Mark this strength as processed
            strengthUsed[s] = true;
        }
        
        // Count unvisited leaves
        int count = 0;
        for (int i = 1; i <= k; i++) {
            if (!visited[i]) {
                count++;
            }
        }
        
        return count;
    }
};