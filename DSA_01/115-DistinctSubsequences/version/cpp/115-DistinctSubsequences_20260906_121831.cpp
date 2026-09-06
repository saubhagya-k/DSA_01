// Last updated: 06/09/2026, 12:18:31
// great question , must do second
1class Solution {
2public:
3
4typedef unsigned long long ull;
5
6ull dp[1001][1001];
7
8ull solve(int n, int m , string& s , string& t){
9    if(m == 0){
10
11        return dp[n][m] = 1;
12    }
13    if(n == 0){
14        return dp[n][m] = 0;
15    }
16
17    if(dp[n][m] != -1){
18        return dp[n][m];
19    }
20
21    if(s[n-1] == t[m-1]){
22        return dp[n][m]=solve(n-1,m-1,s,t)+solve(n-1,m,s,t);
23    }
24    else{
25        return dp[n][m] = solve(n-1,m,s,t);
26    }
27
28    return -1;
29}
30    int numDistinct(string s, string t) {
31
32        int n = s.length();
33        int m = t.length();
34
35        memset(dp,-1,sizeof(dp));
36
37
38        return solve(n,m,s,t);
39
40
41        
42    }
43};