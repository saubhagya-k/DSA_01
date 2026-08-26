// Last updated: 26/08/2026, 21:17:32
1class Solution {
2public:
3    string longestPalindrome(string s) {
4
5        int start = 0;
6        int maxLen = 1;
7
8        auto expand = [&](int l, int r) {
9
10            while (l >= 0 &&
11                   r < s.size() &&
12                   s[l] == s[r]) {
13                l--;
14                r++;
15            }
16
17            int len = r - l - 1;
18
19            if (len > maxLen) {
20                maxLen = len;
21                start = l + 1;
22            }
23        };
24
25        for (int i = 0; i < s.size(); i++) {
26
27            // odd length
28            expand(i, i);
29
30            // even length
31            expand(i, i + 1);
32        }
33
34        return s.substr(start, maxLen);
35    }
36};