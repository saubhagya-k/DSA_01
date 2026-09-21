// Last updated: 21/09/2026, 18:22:23
1class Solution {
2public:
3
4
5
6int memo[101][101];
7
8vector<vector<int>>direction{{1,0},{0,1}};  // down is {1,0} and right is {0,1}
9
10
11int helperdfs(int m,int n,int idx,int idy){
12
13    if(idx==m-1 && idy==n-1){
14
15      
16
17        return 1;
18
19    }
20    
21
22    if(idx<0||idy<0 || idx>=m||idy>=n){
23        return 0;
24    }
25
26    if (memo[idx][idy] != -1) {
27            return memo[idx][idy];
28        }
29
30
31        int  total_ways_from_here = 0;
32
33    for(auto dir : direction){
34       
35
36
37       total_ways_from_here +=  helperdfs(m,n,idx+dir[0],idy+dir[1]);
38
39
40    }
41
42    return memo[idx][idy] = total_ways_from_here;
43
44
45
46
47
48}
49    int uniquePaths(int m, int n) {
50
51        memset(memo,-1,sizeof(memo));
52
53        return helperdfs(m,n,0,0);
54
55
56        
57
58        
59        
60    }
61};