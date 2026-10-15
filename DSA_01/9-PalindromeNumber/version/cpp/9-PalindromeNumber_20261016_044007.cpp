// Last updated: 16/10/2026, 04:40:07
1class Solution {
2public:
3    bool isPalindrome(int x) {
4
5        string a = to_string(x);
6
7        int n = a.length();
8
9        stack<char>st;
10
11        for(int i=0;i<n;i++){
12
13            st.push(a[i]);
14        }
15
16        string b = "";
17
18         while(!st.empty()){
19
20          b+=st.top();
21            
22
23           
24            st.pop();
25
26         }
27        
28
29        return a == b;
30
31
32
33        
34    }
35};