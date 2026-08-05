// Last updated: 05/08/2026, 16:56:08
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxarea = 0;
        

        queue<pair<int,int>>q;
            

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};



        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    
                    q.push({i,j});
                    grid[i][j] = 0;  //marked

                   

                    

                    

                    while(!q.empty()){
                        
                        auto curr = q.front();
                        q.pop();

                        

                        int a = curr.first;
                        int b = curr.second;

                        for(int k=0;k<4;k++){
                            int nr = a + drow[k];
                            int nc = b + dcol[k];

                           

                            if(nr >=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){

                                q.push({nr,nc});
                                grid[nr][nc] = 0;
                               

                            }
                            
                        }
                         area++;

                    }
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
        
    }
};