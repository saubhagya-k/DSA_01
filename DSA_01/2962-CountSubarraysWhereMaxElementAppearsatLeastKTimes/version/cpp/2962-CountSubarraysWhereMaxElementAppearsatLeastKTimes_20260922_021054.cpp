// Last updated: 22/09/2026, 02:10:54
1class Solution {
2public:
3int n,m;
4
5int result;
6
7int free = 0;
8
9vector<vector<int>>direction{{1,0},{-1,0},{0,1},{0,-1}};
10
11void backtrack(vector<vector<int>>& grid,int i,int j,int count){
12    if(i<0 || j<0 ||i>=n||j>=m || grid[i][j] == -1){
13        return ;
14    }
15
16    if(grid[i][j] == 2){
17        if(count == free){
18            result++;
19        }
20        return;
21    }
22
23   grid[i][j] = -1;
24
25    for(auto dir : direction){
26
27        backtrack(grid,i+dir[0],j+dir[1],count+1);
28        
29    }
30
31    grid[i][j] = 0;
32
33
34
35
36}
37    int uniquePathsIII(vector<vector<int>>& grid) {
38
39         n = grid.size();
40         m = grid[0].size();
41
42         int s_i = 0;
43         int s_j = 0;
44
45        
46
47         for(int i=0;i<n;i++){
48            for(int j=0;j<m;j++){
49
50                if(grid[i][j]==0){
51                    free++;
52                }
53
54                if(grid[i][j]==1){
55                    s_i=i;
56                    s_j=j;
57                    free++;
58                }
59
60
61            }
62         }
63
64        int count = 0;
65
66        backtrack(grid,s_i,s_j,count);
67
68        return result;
69
70
71
72
73        
74    }
75};