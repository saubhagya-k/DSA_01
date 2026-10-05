// Last updated: 05/10/2026, 17:31:56
1class Solution {
2public:
3    int scoreOfParentheses(string s) {
4
5        int n = s.length();
6
7        vector<int>final;
8
9        int score = 0;
10        
11        for(int i=0;i<n;i++){
12
13            if(s[i] == '('){
14                
15                final.push_back(score);
16
17                score = 0;
18            }
19            else{
20             if(s[i-1]=='('){
21                score  = final.back()+1;
22            }
23            else{
24                score = final.back()+2*score;
25            }
26
27          final.pop_back();
28            }
29
30            
31
32        }
33
34       return score;
35        
36    }
37};