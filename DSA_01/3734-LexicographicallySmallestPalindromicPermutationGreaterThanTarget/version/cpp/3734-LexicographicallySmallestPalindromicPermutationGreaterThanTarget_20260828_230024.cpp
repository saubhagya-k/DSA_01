// Last updated: 28/08/2026, 23:00:24
1class Solution {
2public:
3    string lexPalindromicPermutation(string s, string target) {
4        int n = s.length();
5        // Special case: length of 1
6        if (n == 1) {
7            return s > target ? s : "";
8        }
9
10        // Count the frequency of each character
11        vector<int> cnt(26, 0);
12        for (char c : s) {
13            cnt[c - 'a']++;
14        }
15
16        // Check if it can form a palindrome and record the characters with odd
17        // occurrences
18        string oddChar = "";
19        for (int i = 0; i < 26; i++) {
20            if (cnt[i] % 2 == 1) {
21                // More than one character appears an odd number of times,
22                // cannot form a palindrome
23                if (oddChar != "") {
24                    return "";
25                }
26                oddChar = string(1, 'a' + i);
27            }
28            cnt[i] /= 2;  // It takes only half the characters to construct the
29                          // left half
30        }
31
32        string prefix = "";
33
34        auto check = [&](char c) -> bool {
35            string left = prefix;
36            left.push_back(c);
37            for (int i = 25; i >= 0; i--) {
38                left.append(cnt[i], 'a' + i);
39            }
40
41            string palindrome = left + oddChar;
42            string reversed_left = left;
43            reverse(reversed_left.begin(), reversed_left.end());
44            palindrome += reversed_left;
45
46            return palindrome > target;
47        };
48
49        // Construct the left part of each digit greedily
50        for (int i = 0; i < n / 2; i++) {
51            bool found = false;
52            // Try to place the smallest character in lexicographical order
53            for (int j = 0; j < 26; j++) {
54                if (cnt[j] == 0) {
55                    continue;
56                }
57
58                cnt[j]--;
59                if (check('a' + j)) {
60                    // If the constructed palindrome is greater than target,
61                    // choose the character
62                    prefix.push_back('a' + j);
63                    found = true;
64                    break;
65                } else {
66                    cnt[j]++;  // Not meeting the conditions, reset the counter
67                }
68            }
69            if (!found) {
70                return "";  // Cannot construct a palindrome larger than target
71            }
72
73            if (prefix[i] >
74                target[i]) {  // prefix is already greater than target
75                string left = prefix;
76                for (int j = 0; j < 26; j++) {
77                    left.append(cnt[j], 'a' + j);
78                }
79                string palindrome = left + oddChar;
80                string reversed_left = left;
81                reverse(reversed_left.begin(), reversed_left.end());
82                palindrome += reversed_left;
83                return palindrome;
84            }
85        }
86
87        // Construct the final palindrome string
88        string ans = prefix + oddChar;
89        string reversed_prefix = prefix;
90        reverse(reversed_prefix.begin(), reversed_prefix.end());
91        ans += reversed_prefix;
92        return ans;
93    }
94};