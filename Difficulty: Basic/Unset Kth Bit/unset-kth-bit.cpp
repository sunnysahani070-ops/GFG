#include <cmath>

class Solution {
public:
    int replaceBit(int n, int k) {
        int total_bits = log2(n) + 1;
        if (k > total_bits) {
            return n;
        }


        int pos_from_right = total_bits - k;

        return n & ~(1 << pos_from_right);
    }
};