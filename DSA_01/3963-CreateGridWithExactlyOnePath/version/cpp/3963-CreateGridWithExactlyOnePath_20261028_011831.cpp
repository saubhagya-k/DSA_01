// Last updated: 28/10/2026, 01:18:31
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4      
5        vector<string> grid(m, string(n, '#'));
6
7       
8        for (int j = 0; j < n; ++j) {
9            grid[0][j] = '.';
10        }
11
12       
13        for (int i = 0; i < m; ++i) {
14            grid[i][n - 1] = '.';
15        }
16
17        return grid;
18    }
19};
20