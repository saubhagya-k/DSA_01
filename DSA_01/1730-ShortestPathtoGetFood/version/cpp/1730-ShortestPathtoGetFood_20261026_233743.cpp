// Last updated: 26/10/2026, 23:37:43
1class Solution {
2public:
3    int getFood(vector<vector<char>>& grid) {
4
5        int n = grid.size();
6        int m = grid[0].size();
7
8        queue<pair<int,int>>q;
9
10        for(int i=0;i<n;i++){
11            for(int j=0;j<m;j++){
12                if(grid[i][j]=='*'){
13                    q.push({i,j});
14                    break;
15                }
16            }
17        }
18
19
20        int dx[] = {-1,1,0,0};
21        int dy[] = {0,0,1,-1};
22
23        int steps = 0;
24
25        while(!q.empty()){
26            int size = q.size();
27
28            for(int i=0;i<size;i++){
29                auto [r,c] = q.front();
30                q.pop();
31
32
33                for(int d=0;d<4;d++){
34                    int nx = r+dx[d];
35                    int ny = c+dy[d];
36
37                    if(nx>=0 && nx<n && ny>=0 && ny<m){
38                        if(grid[nx][ny]=='#'){
39                            return steps+1;
40                        }
41
42                        if(grid[nx][ny] == 'O'){
43                            grid[nx][ny] = 'X';
44                            q.push({nx,ny});
45                        }
46                    }
47                }
48            }
49
50            steps++;
51        }
52
53        return -1;
54
55
56
57        
58    }
59};