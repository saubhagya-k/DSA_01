// Last updated: 19/08/2026, 15:16:34
1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4
5        int n = nums.size();
6        vector<int>final;
7
8        unordered_map<int,int>map;
9
10        for(int X :nums){
11            map[X]++;
12        }
13
14        for(int i=0;i<n;i++){
15            if(map[nums[i]]>=2){
16
17                final.push_back(nums[i]);
18
19                map[nums[i]]--;
20                
21
22            }
23        }
24
25        return final;
26        
27    }
28};