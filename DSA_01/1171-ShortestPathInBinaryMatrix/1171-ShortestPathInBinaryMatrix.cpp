// Last updated: 05/08/2026, 16:54:07
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

       
        queue<pair<int,int>> q;

       
        q.push({0, 0});
        grid[0][0] = 1;   

       
        int drow[8] = {-1,-1,-1, 0,0, 1,1,1};
        int dcol[8] = {-1, 0, 1,-1,1,-1,0,1};

        int dist = 1;

        // BFS
        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto cell = q.front();
                q.pop();

                int r = cell.first;
                int c = cell.second;

                // ✅ reached destination
                if(r == n-1 && c == n-1)
                    return dist;

                for(int i = 0; i < 8; i++) {
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;   // mark visited
                        q.push({nr, nc});
                    }
                }
            }

            dist++;
        }

        return -1;  // no path found
    }
};
