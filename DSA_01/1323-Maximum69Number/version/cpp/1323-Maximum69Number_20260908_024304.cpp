// Last updated: 08/09/2026, 02:43:04
1class Solution {
2public:
3    int maximum69Number (int num) {
4
5        int a = 0;
6
7        int maxi = INT_MIN;
8
9        int i = 0;
10
11        int temp = num;
12
13
14        while(num!=0){
15
16            a = num%10;
17            
18
19            if(a == 6 ){
20
21               maxi = max(maxi,i);
22
23            }
24
25            num = num/10;
26            i++;
27
28        }
29
30        int b = temp+(3*pow(10,maxi));
31
32        return b;
33
34
35        
36    }
37};