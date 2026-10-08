// Last updated: 08/10/2026, 14:01:16
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4
5    string st = "";
6
7        int n = s.length();
8
9        int open =0;
10       
11
12        for(char c:s){
13            if(c=='('){
14               
15
16                if(open>0){
17                    st+=c;
18                }
19
20                open++;
21               
22            }
23            else{
24               open--;
25               if(open>0){
26                st+=c;
27
28               }
29            }
30
31            
32        }
33
34        return st;
35
36
37        
38    }
39};