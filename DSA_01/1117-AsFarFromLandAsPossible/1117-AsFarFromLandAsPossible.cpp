// Last updated: 05/08/2026, 16:54:21
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        if(q.empty() || q.size() == n * n)
            return -1;

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        int ans = 0;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == -1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    ans = max(ans, grid[nr][nc]);
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};
