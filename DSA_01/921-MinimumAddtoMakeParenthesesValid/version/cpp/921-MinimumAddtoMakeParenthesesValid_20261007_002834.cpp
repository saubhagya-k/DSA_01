// Last updated: 07/10/2026, 00:28:34
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4
5        int n = s.length();
6
7        stack<int>st;
8
9        string extra = "";
10
11        int count = 0;
12
13        for(char c: s){
14            if(c=='('){
15                st.push(c);
16            }
17            else if(c==')'){
18                if(!st.empty()){
19                    st.pop();
20                
21                }
22                else{
23                    count++;
24                }
25            }
26
27        }
28
29        return count+st.size();
30        
31    }
32};