#include <vector>
#include <cmath>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Directions array to easily iterate over the 8 neighbors
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Step 1: Analyze current states and encode transitions
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int live_neighbors = 0;
                
                // Count neighbors
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];
                    
                    // Check bounds and count if the neighbor was originally live (1 or 2)
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (board[nr][nc] == 1 || board[nr][nc] == 2) {
                            live_neighbors++;
                        }
                    }
                }
                
                // Apply rules using state encoding
                if (board[r][c] == 1) {
                    if (live_neighbors < 2 || live_neighbors > 3) {
                        board[r][c] = 2; // Rule 1 & 3: Was Live, becomes Dead
                    }
                } else if (board[r][c] == 0) {
                    if (live_neighbors == 3) {
                        board[r][c] = 3; // Rule 4: Was Dead, becomes Live
                    }
                }
            }
        }
        
        // Step 2: Finalize the board state transformations
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 2) board[r][c] = 0; // Transformed to Dead
                if (board[r][c] == 3) board[r][c] = 1; // Transformed to Live
            }
        }
    }
};
