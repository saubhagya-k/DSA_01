// Last updated: 27/08/2026, 12:56:44
class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        auto expand = [&](int l, int r) {

            while (l >= 0 &&
                   r < s.size() &&
                   s[l] == s[r]) {
                l--;
                r++;
            }

            int len = r - l - 1;

            if (len > maxLen) {
                maxLen = len;
                start = l + 1;
            }
        };

        for (int i = 0; i < s.size(); i++) {

            // odd length
            expand(i, i);

            // even length
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};