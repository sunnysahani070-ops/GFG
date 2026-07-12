class Solution {
    class node {
    public:
        int data;
        int row;
        int col;
        
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
    };

    class compare {
    public:
        bool operator()(node* a, node* b) {
            return a->data > b->data;
        }
    };

public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        int n = mat.size();
        int k = mat[0].size();
        
        priority_queue<node*, vector<node*>, compare> pq;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            int val = mat[i][0];
            mini = min(mini, val);
            maxi = max(maxi, val);
            pq.push(new node(val, i, 0));
        }
        
        int start = mini, end = maxi;
        
        while (!pq.empty()) {
            node* curr = pq.top();
            pq.pop();
            
            mini = curr->data;
            
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            
            int nextRow = curr->row;
            int nextCol = curr->col + 1;
            
            delete curr;
            
            if (nextCol < k) {
                int nextVal = mat[nextRow][nextCol];
                maxi = max(maxi, nextVal);
                pq.push(new node(nextVal, nextRow, nextCol));
            } else {
                break;
            }
        }
        
        while (!pq.empty()) {
            delete pq.top();
            pq.pop();
        }
        
        return {start, end};
    }
};