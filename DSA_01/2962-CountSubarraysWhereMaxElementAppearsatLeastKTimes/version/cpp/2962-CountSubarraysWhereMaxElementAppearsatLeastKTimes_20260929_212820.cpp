// Last updated: 29/09/2026, 21:28:20
1class Solution {
2public:
3    long long countSubarrays(vector<int>& nums, int k) {
4
5        int n = nums.size();
6
7        int maxele = *max_element(nums.begin(),nums.end());
8
9        unordered_map<int,int>map;
10
11        long long count = 0;
12
13        int left = 0;
14        int right = 0;
15
16        while(right<n){
17
18            map[nums[right]]++;
19
20            while(map[maxele]>=k){
21
22                count += n-right;
23
24
25                map[nums[left]]--;
26
27                left++;
28
29            }
30
31            right++;
32
33
34        }
35
36        return count;
37        
38    }
39};