#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Structure to bundle item details and their value/weight ratio
    struct Item {
        int value;
        int weight;
        double ratio;
    };

    // Custom comparator to sort items by ratio in descending order
    static bool compare(Item a, Item b) {
        return a.ratio > b.ratio;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items(n);

        // 1. Store items with their calculated value-to-weight ratio
        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i], (double)val[i] / wt[i]};
        }

        // 2. Sort items greedily based on the ratio
        sort(items.begin(), items.end(), compare);

        double totalValue = 0.0;

        // 3. Iterate through sorted items and fill the knapsack
        for (int i = 0; i < n; i++) {
            if (capacity == 0) break; // Knapsack is full

            if (items[i].weight <= capacity) {
                // Take the whole item
                capacity -= items[i].weight;
                totalValue += items[i].value;
            } else {
                // Take the fractional part of the item
                totalValue += items[i].ratio * capacity;
                capacity = 0; // Knapsack becomes full
            }
        }

        return totalValue;
    }
};