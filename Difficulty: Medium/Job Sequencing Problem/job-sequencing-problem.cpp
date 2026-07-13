class Solution {
public:
    // Helper function to find the next available free slot (Standard DSU Find)
    int findAvailableSlot(int slot, vector<int>& parent) {
        if (slot == parent[slot]) {
            return slot;
        }
        // Path compression ensures almost O(1) lookups
        return parent[slot] = findAvailableSlot(parent[slot], parent);
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Step 1: Pair profits and deadlines
        vector<pair<int, int>> jobs(n);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        // Step 2: Sort jobs by profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        // Step 3: Initialize DSU parent array
        // Each slot initially points to itself.
        vector<int> parent(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }
        
        int countJobs = 0;
        int totalProfit = 0;
        
        // Step 4: Process jobs greedily
        for (int i = 0; i < n; i++) {
            int currentProfit = jobs[i].first;
            int currentDeadline = jobs[i].second;
            
            // Find the available slot for this deadline instantly using DSU
            int availableSlot = findAvailableSlot(currentDeadline, parent);
            
            // If the available slot is greater than 0, it means a valid slot exists
            if (availableSlot > 0) {
                // Claim the slot by pointing it to the slot before it (availableSlot - 1)
                parent[availableSlot] = availableSlot - 1;
                
                countJobs++;
                totalProfit += currentProfit;
            }
        }
        
        return {countJobs, totalProfit};
    }
};