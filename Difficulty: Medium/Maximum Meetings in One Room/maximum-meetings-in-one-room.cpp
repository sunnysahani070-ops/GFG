class Solution {
public:
    // 1. Structure to hold all necessary data for a meeting
    struct meet {
        int start;
        int end;
        int id; // To track the original 1-based index
    };

    // 2. Custom comparator following the problem's rules
    static bool compare(meet a, meet b) {
        if (a.end != b.end) {
            return a.end < b.end; // Prefer earlier finish times
        }
        return a.id < b.id; // Tie-breaker: prefer smaller original index
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<meet> meets(n);
        
        // Populate the meetings array
        for (int i = 0; i < n; i++) {
            meets[i] = {s[i], f[i], i + 1}; // i + 1 for 1-based indexing
        }
        
        // Sort meetings based on our greedy criteria
        sort(meets.begin(), meets.end(), compare);
        
        vector<int> result;
        
        // The first meeting in the sorted list will always be selected
        result.push_back(meets[0].id);
        int timeLimit = meets[0].end;
        
        // 3. Iterate through the rest and check if they can be scheduled
        for (int i = 1; i < n; i++) {
            // A meeting can start only if its start time is STRICTLY GREATER than the previous finish time
            if (meets[i].start > timeLimit) {
                result.push_back(meets[i].id);
                timeLimit = meets[i].end; // Update the end time to the current meeting's end
            }
        }
        
        // 4. The problem asks for the selected indices in sorted (increasing) order
        sort(result.begin(), result.end());
        
        return result;
    }
};