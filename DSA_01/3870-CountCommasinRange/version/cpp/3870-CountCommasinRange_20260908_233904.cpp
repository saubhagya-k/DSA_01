// Last updated: 08/09/2026, 23:39:04
1class Solution {
2public:
3    int countCommas(int n) {
4
5        if(n<1000){
6            return 0;
7        }
8
9        long long count = 0;
10
11        if(n>=1000 && n<=100000){
12
13            count = n-1000+1;
14
15        }
16
17
18        return count;
19
20    
21
22        
23        
24    }
25};