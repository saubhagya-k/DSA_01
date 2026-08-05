// Last updated: 05/08/2026, 16:59:17
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int island = 0;

        queue<pair<int,int>>q;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    island++;
                    q.push({i,j});
                    grid[i][j] = '0';
            

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

       

        while(!q.empty()){
           
            auto cell = q.front();
            q.pop();

            int a = cell.first;
            int b = cell.second;



            for(int i=0;i<4;i++){
                int nr = a + drow[i];
                int nc = b + dcol[i];

                if(nr >=0 && nc >=0 && nr < n && nc < m && grid[nr][nc]=='1'){
                     
                    q.push({nr,nc});
                    grid[nr][nc] = '0';
                }
            }
            }
            }

            }
        }
        return island;
        
    }
};