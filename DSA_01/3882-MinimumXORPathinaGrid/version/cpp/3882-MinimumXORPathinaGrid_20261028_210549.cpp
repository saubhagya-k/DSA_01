// Last updated: 28/10/2026, 21:05:49
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
8        //m*n
9        //dp[i][j] = it stores a bitset<1024> {0, 0, 1, 1, 0, .....}
10
11        dp[0][0][grid[0][0]] = 1;
12
13        for(int i = 0; i < m; i++) {
14            for(int j = 0; j < n; j++) {
15                if(i == 0 && j == 0)
16                    continue;
17
18                bitset<1024> up; //[i-1][j]
19                bitset<1024> left; //[i][j-1]
20
21                if(i > 0) {
22                    up = dp[i-1][j];
23                }
24                if(j > 0) {
25                    left = dp[i][j-1];
26                }
27
28                bitset<1024> combined = up | left; //OR operation
29
30                for(int xorVal = 0; xorVal < 1024; xorVal++) {
31                    if(combined[xorVal]) {
32                        int resultXorVal = xorVal ^ grid[i][j];
33                        dp[i][j][resultXorVal] = 1;
34                    }
35                }
36            }
37        }
38
39        //dp[m-1][n-1]
40        for(int xorVal = 0; xorVal < 1024; xorVal++) {
41            if(dp[m-1][n-1][xorVal]) {
42                return xorVal;
43            }
44        }
45
46        return -1;
47
48        
49    }
50};