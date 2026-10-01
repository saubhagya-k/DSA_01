// Last updated: 01/10/2026, 09:34:15
1class Solution {
2public:
3    bool isValid(string s) {
4
5        stack<char>st;
6
7        for(char c : s){
8            if(c=='('){
9                st.push(')');
10            }
11            else if(c=='{'){
12                st.push('}');
13            }
14            else if(c =='[' ){
15                st.push(']');
16
17            }
18            else{
19                if(st.empty() || st.top()!=c){
20                    return false;
21                }
22
23                st.pop();
24            }
25         
26        }
27        return st.empty();
28        
29    }
30};