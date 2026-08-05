// Last updated: 05/08/2026, 16:57:35
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int,int>> q;

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        // -------- PACIFIC OCEAN BFS (top row + left column) --------
        for(int j = 0; j < n; j++) {
            q.push({0, j});
            pacific[0][j] = true;
        }

        for(int i = 0; i < m; i++) {
            q.push({i, 0});
            pacific[i][0] = true;
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n &&
                   !pacific[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {

                    pacific[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        // -------- ATLANTIC OCEAN BFS (bottom row + right column) --------
        while(!q.empty()) q.pop();

        for(int j = 0; j < n; j++) {
            q.push({m-1, j});
            atlantic[m-1][j] = true;
        }

        for(int i = 0; i < m; i++) {
            q.push({i, n-1});
            atlantic[i][n-1] = true;
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n &&
                   !atlantic[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {

                    atlantic[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        // -------- INTERSECTION --------
        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
