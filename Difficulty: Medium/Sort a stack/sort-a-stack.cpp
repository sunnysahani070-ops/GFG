#include <stack>
using namespace std;

class Solution {
public:
    
    void insertSorted(stack<int>& st, int x) {
        // Correct position found
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }

    void sortStack(stack<int>& st) {
        if (st.empty()) {
            return;
        }

        int x = st.top();
        st.pop();

        sortStack(st);

        insertSorted(st, x);
    }
};