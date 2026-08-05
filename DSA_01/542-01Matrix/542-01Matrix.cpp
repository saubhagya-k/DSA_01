// Last updated: 05/08/2026, 16:56:54
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        
        // Step 1: Push all 0s into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i,j});
                } else {
                    mat[i][j] = -1; // mark unvisited
                }
            }
        }
        
        // Directions
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // Step 2: BFS
        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            for(auto [dx,dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m && mat[nx][ny]==-1) {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        
        return mat;
    }
};
