// Last updated: 03/10/2026, 23:55:43
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4
5        int n = s.length();
6
7        int result = 0;
8
9        int open = 0;
10        int close = 0;
11
12      
13
14//left to right
15        for(int i=0;i<n;i++){
16            if(s[i]=='('){
17                open++;
18            }
19            if(s[i]==')'){
20                close++;
21
22            }
23            if(close>open){
24                close = 0;
25                open = 0;
26            }
27            else if(close==open){
28             
29
30                result = max(result,open+close);
31            }
32            
33        }
34
35        // right to left
36
37        open  = 0;
38        close = 0;
39
40
41        for(int i=n-1;i>=0;i--){
42
43            if(s[i]=='('){
44                open++;
45            }
46            if(s[i]==')'){
47                close++;
48            }
49
50            if(open>close){
51                open = 0;
52                close = 0;
53            }
54            else if(open == close){
55                 result = max(result,open+close);
56            }
57
58
59
60        }
61
62        return result;
63        
64    }
65};