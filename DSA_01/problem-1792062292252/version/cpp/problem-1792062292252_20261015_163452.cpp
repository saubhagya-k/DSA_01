// Last updated: 15/10/2026, 16:34:52
1class Solution {
2public:
3    string makeGood(string s) {
4
5        string final = "";
6
7       
8
9       
10
11        int first = 0;
12        int second = 0;
13
14        for(int i=1;i<s.length();i++){
15
16            int first = static_cast<int>(s[i-1]);
17            int second = static_cast<int>(s[i]);
18
19            if(abs(first-second)==32){
20
21                s.erase(i-1,2);
22
23                i = max(0,i-2);    
24
25            }
26            
27        }
28
29       
30
31        return s;
32        
33    }
34};