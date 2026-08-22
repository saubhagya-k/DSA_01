// Last updated: 22/08/2026, 15:12:53
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4
5        stack<char>st;
6
7        int n = s.length();
8
9        if(n==0){
10            return 0;
11        }
12
13        st.push(s[0]);
14
15        int i=1;
16
17       while(i<n){
18       
19        if(!st.empty() && st.top() =='(' && s[i] == ')'){
20            st.pop();
21        }
22        else{
23            st.push(s[i]);
24        }
25        i++;
26       }
27
28       return st.size();
29    }
30};