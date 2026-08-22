// Last updated: 22/08/2026, 14:22:16
1class Solution {
2public:
3    bool checkDivisibility(int n) {
4
5        int a = 0;
6
7        int copy = n;
8
9        int sum= 0;
10        int mul  = 1;
11
12        while(copy>0){
13
14            a = copy%10;
15
16            copy = copy/10;
17
18
19            sum+=a;
20            mul*=a;
21
22
23
24        }
25
26        if(n%(sum+mul)==0){
27            return true;
28        }
29
30
31        else{
32
33            return false;
34
35
36
37        }
38
39        
40        
41    }
42};