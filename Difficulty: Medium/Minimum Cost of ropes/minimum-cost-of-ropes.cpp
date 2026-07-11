#include <vector>
#include <queue>

class Solution {
  public:
    int minCost(std::vector<int>& arr) {
        // Create a min-heap and push all rope lengths into it
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(arr.begin(), arr.end());
        
        int totalCost = 0;
        
        // Connect ropes until only one rope remains
        while (minHeap.size() > 1) {
            // Extract the two smallest ropes
            int first = minHeap.top();
            minHeap.pop();
            
            int second = minHeap.top();
            minHeap.pop();
            
            // The cost to connect them is their sum
            int currentCost = first + second;
            totalCost += currentCost;
            
            // Push the connected rope back into the min-heap
            minHeap.push(currentCost);
        }
        
        return totalCost;
    }
};