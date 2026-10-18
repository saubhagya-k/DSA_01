// Last updated: 18/10/2026, 16:36:11
1class Solution {
2public:
3    int findPeakElement(vector<int>& nums) {
4        int n = nums.size();
5
6        int left  = 0;
7
8        int mid = 0;
9
10        int right = n-1;
11
12        while(left<right){
13
14          mid = left+(right-left)/2;
15
16            if(nums[mid]<nums[mid+1]){
17
18                left = mid+1;
19
20            }
21            else{
22                right = mid;
23            }
24        }
25
26        return left;
27    }
28};