// Last updated: 15/08/2026, 19:29:32
1class Solution {
2public:
3    int findLengthOfLCIS(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int left  = nums[0];
8        int count = 1;
9        int maxle = INT_MIN;
10        int right = 0;
11
12        if(n==1){
13            return 1;
14        }
15
16        for(int i=1;i<n;i++){
17
18            right = nums[i];
19
20            if(right>left){
21                count++;
22            }
23
24            else{
25                count = 1;
26            }
27
28            left = right;
29
30            maxle = max(maxle,count);
31
32        }
33
34        return maxle;
35        
36    }
37};