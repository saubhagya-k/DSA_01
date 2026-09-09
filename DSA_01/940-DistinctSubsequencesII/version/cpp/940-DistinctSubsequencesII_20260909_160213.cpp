// Last updated: 09/09/2026, 16:02:13
1class Solution {
2public:
3typedef unsigned long long ull;
4    ull countCommas(long long n) {
5
6       ull total_comma = 0;
7
8        for(ull x = 1000;x<=n;x*=1000){
9            total_comma += n-x+1;
10        }
11
12        return total_comma;
13        
14    
15        
16
17        
18    }
19};