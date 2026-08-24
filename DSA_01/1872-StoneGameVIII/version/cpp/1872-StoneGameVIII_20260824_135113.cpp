// Last updated: 24/08/2026, 13:51:13
// good problem
1class Solution {
2public:
3
4int n;
5
6vector<int> dp; 
7
8
9    int stoneGameVIII(vector<int>& stones) {
10
11         n = stones.size();
12
13        vector<int> prefix(n);
14
15        dp.assign(n,-1e9);
16
17        prefix[0] = stones[0];
18
19        for(int i=1;i<n;i++){
20            prefix[i] = prefix[i-1]+stones[i];
21        }
22
23       return solve(prefix,1);
24
25
26        
27    }
28
29    int solve(vector<int>&prefix,int i){
30
31    if(i==n-1){
32
33       return prefix[n-1];
34
35    }
36
37    if(dp[i]!=-1e9){
38        return dp[i];
39    }
40
41    int nexstep = solve(prefix,i+1);
42
43
44    int take = prefix[i] - nexstep;
45
46    int skip = nexstep;
47
48
49    return dp[i] = max(take,skip);
50}
51};