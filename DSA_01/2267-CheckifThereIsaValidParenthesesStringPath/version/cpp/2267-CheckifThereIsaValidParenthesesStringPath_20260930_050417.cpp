// Last updated: 30/09/2026, 05:04:17
1class Solution {
2public:
3
4int n,m;
5int o;
6
7int t[101][101][201];
8
9vector<vector<int>>distance{{1,0},{0,1}};
10
11bool helperDFS(int i,int j,int openCount,vector<vector<char>>& grid){
12
13    if(i<0||j<0||i>=n||j>=m){
14        return false;
15    }
16
17    if (grid[i][j] == '$') {
18            return false;
19    }
20
21  
22
23  
24    openCount += (grid[i][j]=='(')?+1:-1;
25
26    if (openCount < 0 || openCount>=201) {
27            return false;
28        }
29
30      if(t[i][j][openCount]!=-1){
31        return t[i][j][openCount];
32    }
33
34
35    if(i==n-1 && j==m-1){
36        return t[i][j][openCount] =  openCount==0?true:false;
37    }
38
39 
40
41    for(auto &dis:distance){
42        int idx = i+dis[0];
43        int idy = j+dis[1];
44
45       if( helperDFS(idx,idy,openCount,grid)){
46  
47        return t[i][j][openCount] = true;
48        
49       }
50
51        
52    }
53
54
55
56    return t[i][j][openCount] = false;
57
58}
59    bool hasValidPath(vector<vector<char>>& grid) {
60
61         n = grid.size();
62         m = grid[0].size();
63
64        int openCount = 0;
65
66        memset(t,-1,sizeof(t));
67
68       return helperDFS(0,0,0,grid);        
69    }
70};