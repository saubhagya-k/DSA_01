// Last updated: 14/10/2026, 21:13:15
1class Solution {
2public:
3    string maxSumOfSquares(int num, int sum) {
4
5        if(sum>num*9){
6            return "";
7        }
8        
9        int nines = sum/9;
10        int rem = sum%9;
11
12        string result(nines,'9');
13
14        if(rem>0){
15            result.push_back(rem+'0');
16        }
17
18        if (num > result.length()) {
19
20        result.append(num-result.length(),'0');
21
22        }
23        
24        return result;
25    }
26};