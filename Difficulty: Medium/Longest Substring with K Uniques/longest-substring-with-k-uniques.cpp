class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int left = 0;
        int distinct = 0;
        int ans = -1;

        vector<int> freq(256, 0);

        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] == 0)
                distinct++;

            freq[s[right]]++;

            while (distinct > k) {
                freq[s[left]]--;

                if (freq[s[left]] == 0)
                    distinct--;

                left++;
            }

            if (distinct == k) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};