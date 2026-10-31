// Last updated: 31/10/2026, 19:04:40
1class Solution {
2public:
3    int countKDifference(vector<int>& nums, int k) {
4
5        int n = nums.size();
6        int count = 0;
7
8        unordered_map<int,int>map;
9
10        for(int i=0;i<n;i++){
11
12            if(map.find(nums[i]-k)!=map.end()){
13                count+=map[nums[i]-k];
14            }
15
16            if(map.find(nums[i]+k)!=map.end()){
17                count+=map[nums[i]+k];
18            }
19
20            map[nums[i]]++;
21        }
22
23        return count;
24        
25    }
26};