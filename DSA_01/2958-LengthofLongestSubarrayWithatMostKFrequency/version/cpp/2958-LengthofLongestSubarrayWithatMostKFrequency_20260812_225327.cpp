// Last updated: 12/08/2026, 22:53:27
1class Solution {
2public:
3    int maxSubarrayLength(vector<int>& nums, int k) {
4
5        int n = nums.size();
6
7       int left = 0;
8       int right = 0;
9
10   
11        int lls =  INT_MIN;
12
13       unordered_map<int,int>map;
14
15
16       for(int right=0;right<n;right++){
17
18        map[nums[right]]++;
19
20
21        while(map[nums[right]]>k){
22
23            map[nums[left]]--;
24
25            left++;
26
27        }
28
29         lls = max(lls,right-left+1);
30
31       }
32
33       return lls;
34
35
36    }
37};