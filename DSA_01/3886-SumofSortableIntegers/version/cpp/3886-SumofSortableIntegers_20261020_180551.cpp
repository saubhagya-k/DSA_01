// Last updated: 20/10/2026, 18:05:51
1#include <vector>
2#include <algorithm>
3
4using namespace std;
5
6class Solution {
7public:
8    // Standard KMP helper function to compute the Longest Prefix Suffix (LPS) array
9    void computeLPSArray(const vector<int>& pattern, int M, vector<int>& lps) {
10        int len = 0;
11        lps[0] = 0;
12        int i = 1;
13        while (i < M) {
14            if (pattern[i] == pattern[len]) {
15                len++;
16                lps[i] = len;
17                i++;
18            } else {
19                if (len != 0) {
20                    len = lps[len - 1];
21                } else {
22                    lps[i] = 0;
23                    i++;
24                }
25            }
26        }
27    }
28
29    // Standard KMP Search algorithm to check if vec1 (pattern) exists in text
30    bool KMPSearch(const vector<int>& pattern, const vector<int>& text) {
31        int M = pattern.size();
32        int N = text.size();
33        
34        if (M == 0) return true; // Empty pattern matches anything
35        if (N < M) return false;
36
37        vector<int> lps(M);
38        computeLPSArray(pattern, M, lps);
39
40        int i = 0; // index for text
41        int j = 0; // index for pattern
42        while ((N - i) >= (M - j)) {
43            if (pattern[j] == text[i]) {
44                j++;
45                i++;
46            }
47            if (j == M) {
48                return true; // Pattern found
49                // j = lps[j - 1]; // uncomment if you need multiple matches
50            } else if (i < N && pattern[j] != text[i]) {
51                if (j != 0)
52                    j = lps[j - 1];
53                else
54                    i = i + 1;
55            }
56        }
57        return false;
58    }
59
60    bool isValid(vector<int>& vec1, vector<int>& vec2) {
61        vector<int> text = vec2;
62        text.insert(end(text), begin(vec2), end(vec2));
63        return KMPSearch(vec1, text);
64    }
65
66    int sortableIntegers(vector<int>& nums) {
67        int n = nums.size();
68        vector<int> sorted = nums;
69        sort(sorted.begin(), sorted.end());
70
71        int result = 0;
72
73        // FIXED 1: Started loop from k = 1 to prevent division-by-zero (n % 0)
74        for (int k = 1; k <= n; k++) {
75            if (n % k != 0) continue;
76
77            bool valid = true;
78
79            for (int start = 0; start < n; start += k) {
80                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
81                
82                // FIXED 2 & 3: Fixed typo '.beign()' and changed 'sorted.begin()' to match 'sorted' vector
83                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);
84
85                if (!isValid(vec1, vec2)) {
86                    valid = false;
87                    break;
88                }
89            }
90
91            if (valid) {
92                result += k;
93            }
94        }
95
96        return result;
97    }
98};
99