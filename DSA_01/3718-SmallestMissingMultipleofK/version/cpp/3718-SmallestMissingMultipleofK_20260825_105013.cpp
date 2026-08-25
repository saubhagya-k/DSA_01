// Last updated: 25/08/2026, 10:50:13
1class Solution {
2public:
3    int missingMultiple(vector<int>& nums, int k) {
4
5       unordered_set<int>seen(nums.begin(),nums.end());
6
7       int ans = k;
8
9       while(seen.count(ans)){
10         ans+=k;
11       }
12
13       return ans;
14
15
16
17        
18    }
19};