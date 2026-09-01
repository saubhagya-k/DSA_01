// Last updated: 02/09/2026, 00:15:11
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int n = digits.size();
5
6        
7        for (int i = n - 1; i >= 0; --i) {
8            
9           
10            if (digits[i] < 9) {
11                digits[i] = digits[i] + 1; 
12                return digits;             
13            }
14            
15            
16            digits[i] = 0;
17        }
18
19        
20        digits.insert(digits.begin(), 1);
21
22        return digits;
23    }
24};
25