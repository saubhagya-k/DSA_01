// Last updated: 31/10/2026, 23:05:15
1class Solution {
2public:
3    long long countBadPairs(vector<int>& nums) {
4
5        long long  n = nums.size();
6        
7
8        for(int i=0;i<n;i++){
9            nums[i] = nums[i]-i;
10        }
11
12     long long totalPairs = (n * (n - 1)) / 2;
13
14     long long good_pairs = 0;
15
16
17
18        unordered_map<int,int>map;
19
20       for(int i=0;i<n;i++){
21
22        if(map.find(nums[i]) != map.end()){
23            good_pairs+=map[nums[i]];
24        }
25        map[nums[i]]++;
26        
27        
28       }
29
30       return totalPairs-good_pairs;
31
32
33    }
34
35
36};