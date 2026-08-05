// Last updated: 05/08/2026, 16:52:16
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Edge cases: if the start or end cell has a thief, safeness factor is 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // Direction arrays for moving up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        //  FIXED: Corrected the inner vector initialization syntax
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all thieves into the queue for multi-source BFS
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        // Run Multi-Source BFS to compute distance to nearest thief for all cells
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                // If neighbor is within bounds and hasn't been visited yet
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Use a Max-Priority Queue (Dijkstra variant) to find the safest path
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        //  FIXED: Corrected this 2D vector initialization as well
        vector<vector<int>> max_safeness(n, vector<int>(n, -1));

        pq.push({dist[0][0], {0, 0}});
        max_safeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [current_safeness, cell] = pq.top();
            auto [r, c] = cell;
            pq.pop();

            // If we reached the bottom-right corner, return the answer
            if (r == n - 1 && c == n - 1) {
                return current_safeness;
            }

            // If we found a worse safeness factor than already recorded, skip it
            if (current_safeness < max_safeness[r][c]) {
                continue;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    // The safeness of moving to the neighbor is limited by the minimum 
                    // distance to a thief along the entire path
                    int next_safeness = min(current_safeness, dist[nr][nc]);

                    // If this path offers a higher safeness factor than previously found for (nr, nc)
                    if (next_safeness > max_safeness[nr][nc]) {
                        max_safeness[nr][nc] = next_safeness;
                        pq.push({next_safeness, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
