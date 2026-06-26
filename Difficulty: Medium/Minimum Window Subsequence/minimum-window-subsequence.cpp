class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int start = -1;
        int minLen = INT_MAX;

        int i = 0;

        while (i < n) {
            int j = 0;

            // Forward scan: find complete subsequence
            while (i < n) {
                if (s1[i] == s2[j])
                    j++;

                if (j == m)
                    break;

                i++;
            }

            if (i == n)
                break;

            // End of valid window
            int end = i + 1;

            // Backward scan: minimize window
            j = m - 1;

            while (j >= 0) {
                if (s1[i] == s2[j])
                    j--;

                i--;
            }

            i++; // actual start

            if (end - i < minLen) {
                minLen = end - i;
                start = i;
            }

            // Continue searching
            i++;
        }

        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
