// Last updated: 03/10/2026, 23:56:45
1#include <string>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    int longestValidParentheses(string s) {
9        // Fast I/O optimization for LeetCode
10        ios_base::sync_with_stdio(false);
11        cin.tie(NULL);
12
13        int n = s.length();
14        if (n == 0) return 0; // Early exit
15
16        int result = 0;
17        int open = 0;
18        int close = 0;
19
20        // 1. Left to Right Pass
21        for (int i = 0; i < n; i++) {
22            if (s[i] == '(') {
23                open++;
24            } else { // Changed to else because s[i] can only be '(' or ')'
25                close++;
26            }
27
28            if (close > open) {
29                close = 0;
30                open = 0;
31            } else if (close == open) {
32                result = max(result, open + close);
33            }
34        }
35
36        // Reset counters
37        open = 0;
38        close = 0;
39
40        // 2. Right to Left Pass
41        for (int i = n - 1; i >= 0; i--) {
42            if (s[i] == '(') {
43                open++;
44            } else { // Changed to else
45                close++;
46            }
47
48            if (open > close) {
49                open = 0;
50                close = 0;
51            } else if (open == close) {
52                result = max(result, open + close);
53            }
54        }
55
56        return result;
57    }
58};
59