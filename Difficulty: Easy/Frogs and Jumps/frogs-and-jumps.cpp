class Solution {
  public:
    int unvisitedLeaves(vector<int>& arr, int k) {
        int n = arr.size(); 
       
        vector<bool> visited(k + 1, false);
        

        vector<bool> strengthUsed(k + 1, false);
        
        for (int i = 0; i < n; i++) {
            int s = arr[i];
            
           
            if (s > k) continue;
  
            if (strengthUsed[s]) continue;
   
            for (int j = s; j <= k; j += s) {
                visited[j] = true;
            }
     
            strengthUsed[s] = true;
        }

        int count = 0;
        for (int i = 1; i <= k; i++) {
            if (!visited[i]) {
                count++;
            }
        }
        
        return count;
    }
};