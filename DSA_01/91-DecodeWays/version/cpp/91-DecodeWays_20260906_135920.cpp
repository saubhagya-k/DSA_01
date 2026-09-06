// Last updated: 06/09/2026, 13:59:20
1class Solution {
2public:
3
4int dp[101];
5
6int solve(int i,string& s , int n){
7
8    if(i==n){
9         return dp[i] = 1;
10    }
11
12    if(s[i]== '0'){
13        return dp[i] = 0;
14    }
15
16    if(dp[i] != -1){
17       return dp[i];
18    }
19
20    int result = solve(i+1,s,n);
21
22    if(i+1<n){
23        if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
24            result += solve(i+2,s,n);
25        }
26    }
27
28    return dp[i] = result;
29
30    
31   
32    
33}
34    int numDecodings(string s) {
35
36        int n = s.length();
37
38        memset(dp,-1,sizeof(dp));
39
40        return solve(0,s,n);
41        
42    }
43};