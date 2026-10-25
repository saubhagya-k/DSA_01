// Last updated: 25/10/2026, 19:14:58
1class Solution {
2public:
3int m,n;
4
5bool dfs(vector<vector<int>>& grid,int r,int c){
6    
7    if(r<0 || r>=n || c<0 || c>=m){
8        return false;
9    }
10    if(grid[r][c]==1){
11        return true;
12    }
13
14    grid[r][c] = 1;
15
16    bool updfs = dfs(grid,r,c-1);
17    bool downdfs = dfs(grid,r,c+1);
18    bool leftdfs = dfs(grid,r-1,c);
19    bool rightdfs = dfs(grid,r+1,c);
20
21    return updfs && downdfs && leftdfs && rightdfs;
22
23
24}
25    int closedIsland(vector<vector<int>>& grid) {
26
27       n = grid.size();
28       m = grid[0].size();
29
30        int count = 0;
31
32        for(int i=0;i<n;i++){
33            for(int j=0;j<m;j++){
34
35                if(grid[i][j]==0){
36                if(dfs(grid,i,j)== true){
37
38                    count++;
39
40                }
41                }
42            }
43        }
44
45    
46        return count;
47    }
48};