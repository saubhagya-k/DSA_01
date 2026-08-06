// Last updated: 06/08/2026, 17:32:40
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4
5       while(true){
6        if(final(n,t)){
7
8            return n;
9
10        }
11        n++;
12       }
13      
14    }
15
16    int final(int n,int t){
17
18        long long product =1;
19
20        while(n>0){
21            int a = n%10;
22
23            product *=a;
24            n = n/10;
25
26
27        }
28
29        
30        
31
32        return (product%t==0);
33
34
35
36    }
37};