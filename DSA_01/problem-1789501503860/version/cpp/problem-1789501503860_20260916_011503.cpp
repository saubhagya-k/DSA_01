// Last updated: 16/09/2026, 01:15:03
1class Solution {
2public:
3    int minCut(string s) {
4        int n = s.length();
5        if (n <= 1) return 0;
6
7        // Step 1: Precalculate all palindromes using a 2D DP matrix
8        // isPal[i][j] will be true if substring s[i...j] is a palindrome
9        vector<vector<bool>> isPal(n, vector<bool>(n, false));
10        
11        for (int i = n - 1; i >= 0; i--) {
12            for (int j = i; j < n; j++) {
13                if (s[i] == s[j]) {
14                    // It's a palindrome if it's 1-2 chars long, OR if the inner substring is a palindrome
15                    if (j - i <= 2 || isPal[i + 1][j - 1]) {
16                        isPal[i][j] = true;
17                    }
18                }
19            }
20        }
21
22        // Step 2: Linear DP to find the minimum cuts
23        // cuts[i] stores the minimum cuts needed for the prefix s[0...i]
24        vector<int> cuts(n, 0);
25        
26        for (int i = 0; i < n; i++) {
27            // If the whole prefix s[0...i] is already a palindrome, 0 cuts are needed!
28            if (isPal[0][i]) {
29                cuts[i] = 0;
30            } else {
31                // Otherwise, assume the maximum cuts possible (cutting every single character)
32                int min_cuts = i; 
33                
34                // Try cutting at every possible position 'j'
35                for (int j = 1; j <= i; j++) {
36                    if (isPal[j][i]) {
37                        min_cuts = min(min_cuts, cuts[j - 1] + 1);
38                    }
39                }
40                cuts[i] = min_cuts;
41            }
42        }
43
44        // Return the final answer for the entire string s[0...n-1]
45        return cuts[n - 1];
46    }
47};
48