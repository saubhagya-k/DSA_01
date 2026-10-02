// Last updated: 02/10/2026, 23:23:41
1class Solution {
2private:
3    void backtrack(vector<string>& result, string& current, int open, int close, int n) {
4        // Base case: A valid combination of length 2*n is found
5        if (current.length() == n * 2) {
6            result.push_back(current);
7            return;
8        }
9
10        // Action 1: Add an opening bracket if we haven't reached the limit 'n'
11        if (open < n) {
12            current.push_back('(');
13            backtrack(result, current, open + 1, close, n);
14            current.pop_back(); // Backtrack step: undo the choice
15        }
16
17        // Action 2: Add a closing bracket if it matches an open bracket
18        if (close < open) {
19            current.push_back(')');
20            backtrack(result, current, open, close + 1, n);
21            current.pop_back(); // Backtrack step: undo the choice
22        }
23    }
24
25public:
26    vector<string> generateParenthesis(int n) {
27        vector<string> result;
28        string current = "";
29        backtrack(result, current, 0, 0, n);
30        return result;
31    }
32};
33