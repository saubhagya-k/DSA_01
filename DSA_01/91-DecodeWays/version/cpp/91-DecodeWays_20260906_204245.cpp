// Last updated: 06/09/2026, 20:42:45
1class Solution {
2public:
3    int numDecodings(string s) {
4        long long MOD = 1e9 + 7;
5        int n = s.length();
6        
7        
8        long long first = 1; 
9        long long second = 0; 
10        long long current = 0;
11
12       
13        for (int i = n - 1; i >= 0; i--) {
14            current = 0;
15            
16           
17            if (s[i] == '*') {
18                current = (9 * first) % MOD;
19            } else if (s[i] != '0') {
20                current = first;
21            }
22
23           
24            if (i + 1 < n) {
25                long long ways2 = 0;
26                
27                if (s[i] != '*' && s[i+1] != '*') {
28                 
29                    int num = (s[i] - '0') * 10 + (s[i+1] - '0');
30                    if (num >= 10 && num <= 26) ways2 = 1;
31                } 
32                else if (s[i] == '*' && s[i+1] == '*') {
33                    
34                    ways2 = 15; 
35                } 
36                else if (s[i] == '*') {
37                  
38                    if (s[i+1] <= '6') ways2 = 2; 
39                    else ways2 = 1;               
40                } 
41                else if (s[i+1] == '*') {
42                   
43                    if (s[i] == '1') ways2 = 9;   
44                    else if (s[i] == '2') ways2 = 6; 
45                }
46                
47                
48                if (second != 0) {
49                    current = (current + (ways2 * second)) % MOD;
50                } else if (ways2 > 0 && i + 2 == n) {
51                   
52                    current = (current + ways2) % MOD;
53                }
54            }
55
56            // Roll the states forward for the next loop iteration
57            second = first;
58            first = current;
59        }
60
61        return current;
62    }
63};
64