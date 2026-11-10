// Last updated: 10/11/2026, 21:40:30
1class Solution {
2public:
3
4int robLinear(vector<int>& nums,int start,int end){
5
6    int length = end-start+1;
7
8    if(length == 1) return nums[start];
9
10    vector<int>linear_dp(length,0);
11
12    linear_dp[0] = nums[start];
13    linear_dp[1] = max(nums[start],nums[start+1]);
14
15    for(int i=2;i<length;i++){
16
17        linear_dp[i] = max(linear_dp[i-1],nums[i+start]+linear_dp[i-2]);
18
19
20        
21    }
22
23    return linear_dp[length - 1];
24
25}
26    int rob(vector<int>& nums) {
27
28        int n = nums.size();
29
30        if(n==0) return 0;
31
32        if(n==1) return nums[0];
33
34        int case1 = robLinear(nums,0,n-2);
35
36        int case2 = robLinear(nums,1,n-1);
37
38        return max(case1, case2);
39        
40    }
41};