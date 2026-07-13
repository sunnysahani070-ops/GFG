class Solution {
public:
    int solve(vector<int>& bt) {
        // Step 1: Sort burst times in ascending order
        sort(bt.begin(), bt.end());
        
        int totalWaitingTime = 0;
        int currentTime = 0;
        
        // Step 2: Calculate waiting time for each process
        for (int i = 0; i < bt.size(); i++) {
            totalWaitingTime += currentTime; // Add the time this process had to wait
            currentTime += bt[i];            // Update current time after this process executes
        }
        
        // Step 3: Return the floor of the average waiting time
        return totalWaitingTime / bt.size();
    }
};