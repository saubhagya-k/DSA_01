// Last updated: 22/10/2026, 00:37:46
1class Solution {
2public:
3    int findKthLargest(vector<int>& nums, int k) {
4
5        sort(nums.begin(),nums.end(),std::greater<int>());
6
7        int ans = 0;
8
9        for(int i=0;i<k;i++){
10            if(i==k-1){
11
12                ans = nums[i];
13
14            }
15        }
16
17        return ans;
18        
19    }
20};