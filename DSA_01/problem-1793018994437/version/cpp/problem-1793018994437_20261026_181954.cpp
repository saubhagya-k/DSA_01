// Last updated: 26/10/2026, 18:19:54
1class Solution {
2public:
3int count = 1;
4int real = 0;
5
6int n,m;
7
8vector<pair<int,int>>direction = {{1,0},{-1,0},{0,1},{0,-1}};
9
10long long  dfs(vector<vector<int>>& grid,int i,int j){
11
12    
13
14    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == 0){
15       return 0;
16    }
17
18    long long  current_val = grid[i][j];
19
20    grid[i][j] = 0;
21
22   
23
24    long long  curr_island = current_val;;
25
26    for(auto dir : direction){
27        int next_i = i+dir.first;
28        int next_j = j+dir.second;
29        curr_island+=dfs(grid,next_i,next_j);
30    }
31
32    return curr_island;
33
34
35
36}
37    int countIslands(vector<vector<int>>& grid, int k) {
38
39         if (grid.empty() || grid[0].empty()) return 0;
40        
41         n = grid.size();
42         m = grid[0].size();
43
44        
45
46         int valid_islands = 0;
47
48        for(int i=0;i<n;i++){
49            for(int j=0;j<m;j++){
50                if(grid[i][j]>0){
51                    long long  island_size = dfs(grid,i,j);
52
53                    if(island_size % k == 0){
54                        valid_islands++;
55                    }
56                }
57            }
58        }
59
60        return valid_islands;
61    }
62};