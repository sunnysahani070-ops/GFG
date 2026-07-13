class Solution {
public:
    int pageFaults(vector<int>& pages, int c) {
        // Hash map to store the page value and its corresponding iterator in the list
        unordered_map<int, list<int>::iterator> mp;
        // Doubly linked list to keep track of the most recently used (front) 
        // and least recently used (back) pages
        list<int> lrulist;
        
        int faults = 0;
        
        for (int i = 0; i < pages.size(); i++) {
            int currentPage = pages[i];
            
            // Scenario 1: Page is not present in memory (Page Fault)
            if (mp.find(currentPage) == mp.end()) {
                faults++;
                
                // If memory capacity is full, remove the least recently used page
                if (lrulist.size() == c) {
                    int lruPage = lrulist.back();
                    lrulist.pop_back();
                    mp.erase(lruPage); // Remove from map
                }
            } 
            // Scenario 2: Page is already in memory (Page Hit)
            else {
                // Remove the page from its current position in the list
                lrulist.erase(mp[currentPage]);
            }
            
            // Insert the current page at the front (most recently used position)
            lrulist.push_front(currentPage);
            // Update/Insert the page mapping with the new list iterator position
            mp[currentPage] = lrulist.begin();
        }
        
        return faults;
    }
};