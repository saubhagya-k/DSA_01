// Last updated: 08/08/2026, 22:32:52
1class Solution {
2public:
3    int lengthOfLIS(vector<int>& nums) {
4
5        int n = nums.size();
6
7        int maxlis = 1;
8
9
10        vector<int>t(n,1);
11
12        for(int i=0;i<n;i++){
13            for(int j=0;j<i;j++){
14
15                if(nums[j]<nums[i]){
16                    t[i] = max(t[i],t[j]+1);
17
18                    maxlis = max(maxlis,t[i]);
19                }
20
21            }
22        }
23
24        return maxlis;
25        
26    }
27};