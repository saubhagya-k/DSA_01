// Last updated: 27/09/2026, 18:48:04
1class Solution {
2public:
3
4vector<vector<int>>must{{1,0},{-1,0},{0,1},{0,-1}};
5    int shortestPath(vector<vector<int>>& grid, int k) {
6
7        int n = grid.size();
8        int m = grid[0].size();
9
10        queue<vector<int>>q;
11
12        int i=0;
13        int j=0;
14
15        q.push({0,0,k});
16
17       
18
19
20        bool visited[41][41][1601];
21        memset(visited,false,sizeof(visited));
22
23          visited[0][0][k] = true;
24
25        int steps = 0;
26
27
28        while(!q.empty()){
29            int size = q.size();
30
31            while(size--){
32                vector<int>temp = q.front();
33                q.pop();
34
35
36                int temp_i = temp[0];
37                int temp_j = temp[1];
38                int obs = temp[2];
39
40                for(auto &mi:must){
41                    int idx = mi[0]+temp_i;
42                    int idy = mi[1]+temp_j;
43                
44
45                if (temp_i == n - 1 && temp_j == m - 1) {
46                    return steps;
47                }
48
49                if(idx<0||idy<0||idx>=n||idy>=m){
50                    continue;
51                }
52
53                if(grid[idx][idy]==0 && !visited[idx][idy][obs]){
54                    q.push({idx,idy,obs});
55
56                    visited[idx][idy][obs] = true;
57                }
58
59                else if(grid[idx][idy]==1  && obs>0  && !visited[idx][idy][obs-1]){
60                    q.push({idx,idy,obs-1});
61                     visited[idx][idy][obs-1] = true;
62                }
63
64
65
66
67            }
68
69            }
70            steps++;
71        }
72
73        return -1;
74        
75    }
76};