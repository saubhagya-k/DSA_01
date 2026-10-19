// Last updated: 19/10/2026, 22:59:21
1class Solution {
2public:
3    vector<int> targetIndices(vector<int>& nums, int target) {
4
5        sort(nums.begin(),nums.end());
6
7        vector<int>final;
8
9        int n = nums.size();
10
11        for(int i=0;i<n;i++){
12            if(nums[i] == target){
13
14                final.push_back(i);
15
16            }
17        }
18
19        return final;
20        
21    }
22};