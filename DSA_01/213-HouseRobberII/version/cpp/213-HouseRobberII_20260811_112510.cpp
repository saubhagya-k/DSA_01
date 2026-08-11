// Last updated: 11/08/2026, 11:25:10
1class Solution {
2public:
3
4int t[101];
5
6int solve(vector<int>& nums,int start,int end){
7
8    if(start>end){
9        return 0;
10    }
11
12    if(t[start]!=-1){
13        return t[start];
14    }
15
16    int take = nums[start]+solve(nums,start+2,end);
17
18    int skip = solve(nums,start+1,end);
19
20    return t[start] = max(take,skip);
21
22}
23    int rob(vector<int>& nums) {
24
25        int  n = nums.size();
26
27        if(n==1){
28            return nums[0];
29        }
30
31        if(n==2){
32            return max(nums[0],nums[1]);
33        }
34
35        memset(t,-1,sizeof(t));
36
37        
38        int take_index_0 = solve(nums,0,n-2);
39
40         memset(t,-1,sizeof(t));
41
42
43        int take_1_index = solve(nums,1,n-1);
44
45
46        return max(take_index_0,take_1_index);
47        
48    }
49};