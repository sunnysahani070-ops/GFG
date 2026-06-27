class Solution {
    void insertAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

public:
    void reverseStack(stack<int>& st) {
        if (st.empty()) {
            return;
        }

        int x = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, x);
    }
};