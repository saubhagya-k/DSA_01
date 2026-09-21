// Last updated: 21/09/2026, 19:36:25
1class Solution {
2public:
3
4int memo[101][101];
5
6vector<vector<int>>direction{{1,0},{0,1}};  // down,right
7int n,m;
8int unique_path(int n,int m,int idx,int idy,vector<vector<int>>& obstacleGrid){
9
10     if(idx<0 ||idy<0 || idx>=n||idy>=m || obstacleGrid[idx][idy] == 1){
11
12        return 0;
13
14    }
15
16
17    if(idx==n-1 && idy==m-1){
18        return 1;
19    }
20    
21    if(memo[idx][idy]!=-1){
22        return memo[idx][idy];
23    }
24
25   
26
27    int total_path = 0;
28
29    for(auto dir :direction){
30        
31        total_path+=unique_path(n,m,idx+dir[0],idy+dir[1],obstacleGrid);
32    }
33
34    return memo[idx][idy] = total_path;
35
36
37
38    
39
40}
41    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
42        
43         n = obstacleGrid.size();
44         m = obstacleGrid[0].size();
45
46         memset(memo,-1,sizeof(memo));
47
48        return unique_path(n,m,0,0,obstacleGrid);
49    }
50};