// Last updated: 07/10/2026, 23:58:17
1class Solution {
2private:
3    std::vector<std::string> result;
4
5    // Helper function to check if a string has valid parentheses
6    bool isValid(const std::string& s) {
7        int count = 0;
8        for (char c : s) {
9            if (c == '(') count++;
10            else if (c == ')') {
11                count--;
12                if (count < 0) return false;
13            }
14        }
15        return count == 0;
16    }
17
18    // DFS Backtracking function
19    void backtrack(const std::string& s, int index, int remOpen, int remClose) {
20        // Base Case: If we have removed the exact number of required parentheses
21        if (remOpen == 0 && remClose == 0) {
22            if (isValid(s)) {
23                result.push_back(s);
24            }
25            return;
26        }
27
28        for (int i = index; i < s.length(); ++i) {
29            // Optimization: Skip duplicates to avoid generating duplicate valid strings
30            if (i > index && s[i] == s[i - 1]) continue;
31
32            // Optimization: If remaining characters are fewer than required removals, stop
33            if (remOpen + remClose > s.length() - i) return;
34
35            // Try removing a closing parenthesis
36            if (remClose > 0 && s[i] == ')') {
37                std::string nextState = s.substr(0, i) + s.substr(i + 1);
38                backtrack(nextState, i, remOpen, remClose - 1);
39            }
40            
41            // Try removing an opening parenthesis
42            if (remOpen > 0 && s[i] == '(') {
43                std::string nextState = s.substr(0, i) + s.substr(i + 1);
44                backtrack(nextState, i, remOpen - 1, remClose);
45            }
46        }
47    }
48
49public:
50    std::vector<std::string> removeInvalidParentheses(std::string s) {
51        result.clear();
52        int remOpen = 0;  // Misplaced '(' that must be removed
53        int remClose = 0; // Misplaced ')' that must be removed
54
55        // Step 1: Calculate the exact minimum number of '(' and ')' to remove
56        for (char c : s) {
57            if (c == '(') {
58                remOpen++;
59            } else if (c == ')') {
60                if (remOpen > 0) {
61                    remOpen--; // Matched a valid pair
62                } else {
63                    remClose++; // Unmatched close parenthesis
64                }
65            }
66        }
67
68        // Step 2: Start DFS backtracking to find all unique valid combinations
69        backtrack(s, 0, remOpen, remClose);
70        
71        return result;
72    }
73};
74