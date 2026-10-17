// Last updated: 17/10/2026, 14:36:37
1class Solution {
2public:
3    int firstMissingPositive(vector<int>& nums) {
4        int n = nums.size();
5        
6       
7        sort(nums.begin(), nums.end());
8
9        
10        int expected_positive = 1;
11
12      
13        for (int i = 0; i < n; i++) {
14            
15            
16            if (nums[i] <= 0) {
17                continue;
18            }
19
20            
21            if (i > 0 && nums[i] == nums[i-1]) {
22                continue;
23            }
24
25            
26            if (nums[i] == expected_positive) {
27                expected_positive++;
28            }
29        }
30
31       
32        return expected_positive;
33    }
34};
35