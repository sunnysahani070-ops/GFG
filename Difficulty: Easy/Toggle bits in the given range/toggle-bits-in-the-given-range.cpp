class Solution {
  public:
    int toggleBits(int n, int l, int r) {
        long long mask = ((1LL << (r - l + 1)) - 1) << (l - 1);

        return n ^ mask;
    }
};