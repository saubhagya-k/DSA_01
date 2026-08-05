// Last updated: 05/08/2026, 16:51:55
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int minRow = grid.size();
        int maxRow = -1;
        int minCol = grid[0].size();
        int maxCol = -1;


        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] == 1) {
                    minRow = min(minRow, r);
                    maxRow = max(maxRow, r);
                    minCol = min(minCol, c);
                    maxCol = max(maxCol, c);
                }
            }
        }


        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

       
        return height * width;

    }
};