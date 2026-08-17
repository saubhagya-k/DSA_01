// Last updated: 17/08/2026, 14:02:52
1class Solution {
2public:
3
4int n;
5
6int t[2501][2502];
7
8int solve(vector<int>& nums,int i,int p){
9
10    int take = 0;
11
12    if (t[i][p + 1] != -1) {
13            return t[i][p + 1];
14        }
15        
16    if(i>=n){
17
18        return 0;
19        }
20
21    if(p==-1 || nums[i]>nums[p]){
22       take = 1+solve(nums,i+1,i);
23    }
24    int skip = solve(nums,i+1,p);
25
26
27    return t[i][p+1] = max(take,skip);
28
29}
30    int lengthOfLIS(vector<int>& nums) {
31
32     n = nums.size();
33
34
35        
36    memset(t,-1,sizeof(t));
37      return solve(nums,0,-1);
38        
39    }
40};