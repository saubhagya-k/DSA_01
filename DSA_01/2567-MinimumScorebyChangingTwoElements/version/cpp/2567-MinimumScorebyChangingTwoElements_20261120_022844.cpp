// Last updated: 20/11/2026, 02:28:44
1class Solution {
2public:
3    int minimizeSum(vector<int>& nums) {
4
5        sort(nums.begin(),nums.end());
6
7        int n = nums.size();
8
9        int dropTwosmallest = nums[n-1] - nums[2];
10        int droponeEach  = nums[n-2] - nums[1];
11        int dropTwoLargest = nums[n-3] - nums[0];
12
13
14        return min({dropTwosmallest,droponeEach,dropTwoLargest});
15        
16    }
17};