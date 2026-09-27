// Last updated: 28/09/2026, 02:17:31
1
2
3class Solution {
4public:
5    string reverseParentheses(string s) {
6        vector<char> st; // This vector acts as our stack bucket
7        
8        for (char c : s) {
9            if (c == ')') {
10                string temp = "";
11                
12                // 1. Pop letters out until we find the matching '('
13                // Because we take them from the top, they are already reversed!
14                while (!st.empty() && st.back() != '(') {
15                    temp += st.back();
16                    st.pop_back();
17                }
18                
19                // 2. Remove the '(' from the stack
20                if (!st.empty()) {
21                    st.pop_back();
22                }
23                
24                // 3. Put the reversed letters back into the stack
25                for (char tc : temp) {
26                    st.push_back(tc);
27                }
28            } else {
29                // Otherwise, just push letters and '(' into the stack
30                st.push_back(c);
31            }
32        }
33        
34        // 4. Build the final string from the remaining characters in the stack
35        return string(st.begin(), st.end());
36    }
37};
38