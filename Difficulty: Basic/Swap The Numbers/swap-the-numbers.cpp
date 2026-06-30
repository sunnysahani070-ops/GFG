class Solution {
public:
    void swap(int &a, int &b) {
        if (&a == &b) return;

        a ^= b;
        b ^= a;
        a ^= b;
    }
};