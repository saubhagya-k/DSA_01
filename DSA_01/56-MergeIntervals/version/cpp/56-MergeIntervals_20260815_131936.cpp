// Last updated: 15/08/2026, 13:19:36
1class Solution {
2public:
3    int maxPower(string s) {
4
5        int n = s.length();
6        int curr = 0;
7
8        int prev = s[0];
9
10        int maxfre = 0;
11
12        int count = 1;
13
14        if(n==1){
15            return 1;
16        }
17
18        // we will sue here two pointers
19
20        for(int i = 1;i<n;i++){
21            curr = s[i];
22
23            if(curr == prev){
24
25                count++;
26                
27            }
28            
29        if(curr!=prev){
30            count = 1;
31         }
32
33          prev = curr;
34
35         maxfre = max(maxfre,count);
36
37
38
39        }
40
41        return maxfre;
42        
43    }
44};