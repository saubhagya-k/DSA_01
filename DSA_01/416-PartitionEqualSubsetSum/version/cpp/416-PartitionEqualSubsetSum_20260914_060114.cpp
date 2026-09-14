// Last updated: 14/09/2026, 06:01:14
1class Solution {
2public:
3
4int t[200+1][10000+1];
5
6bool solve(int n,vector<int>& nums, int sum){
7
8    if(sum==0){
9        return true;
10    }
11    if(n==0){
12        return false;
13    }
14
15    if(t[n][sum] != -1){
16        return t[n][sum];
17    }
18
19    bool skip = solve(n-1,nums,sum);
20
21    bool take = false;
22
23    if (nums[n - 1] <= sum) { 
24            take = solve(n - 1, nums, sum - nums[n - 1]);
25        }
26
27    return t[n][sum] = skip||take;
28
29}
30    bool canPartition(vector<int>& nums) {
31
32        int n = nums.size();
33
34        int sum = 0;
35
36        for(int i=0;i<n;i++){
37
38            sum+=nums[i];
39
40        }
41
42          if (sum % 2 != 0) {
43            return false;
44        }
45        sum = sum/2;
46
47        memset(t, -1, sizeof(t));
48
49       return solve(n,nums,sum);
50        
51    }
52};