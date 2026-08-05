// Last updated: 05/08/2026, 16:54:26
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i == 0  || j == 0 || i == m-1 || j == n-1) && grid[i][j] == 1 ){

              

                q.push({i,j});
                grid[i][j] = 0;
                }
            }

            

                
        }
        
                
        

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int a = cell.first;
            int b = cell.second;

            for(int k=0;k<4;k++){

            int nr = a + drow[k];
            int nc = b + dcol[k];

             if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    grid[nr][nc] = 0;

            

            }
    

            

            


            }
        }
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }

         return count;
       
        
    }
};