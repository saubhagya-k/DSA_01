// Last updated: 09/11/2026, 01:37:18
1class Solution {
2public:
3    int countServers(vector<vector<int>>& grid) {
4
5        int n = grid.size();
6        int m = grid[0].size();
7
8
9        vector<int>row(n,0);
10        vector<int>col(m,0);
11        vector<pair<int, int>> servers;
12
13        for(int i=0;i<n;i++){
14            for(int j=0;j<m;j++){
15                if(grid[i][j] == 1){
16                    row[i]++;
17                    col[j]++;
18
19                    servers.push_back({i,j});
20
21
22                }
23            }
24        }
25
26
27        int ans = 0;
28
29        for(auto [r,c] : servers){
30            if(row[r]>1 || col[c]>1){
31                ans++;
32            }
33        }
34
35        return ans;
36
37
38        
39    }
40};