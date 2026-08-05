// Last updated: 05/08/2026, 16:52:55
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();

      


        int a = entrance[0];
        int b = entrance[1];

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        maze[a][b] = '+';

        queue<pair<int,int>>q;

        q.push({a,b});

       

           int step = 0; 
        
        while(!q.empty()){
            int size = q.size();
            step++;

            while(size--){
                auto [r,c] = q.front();

                q.pop();
                for(int o=0;o<4;o++){
                int nr = r+drow[o];
                int nc = c+dcol[o];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && maze[nr][nc] == '.'){

                    if(nr == 0 || nc == 0 || nr == m-1 || nc == n-1)
                            return step;


                    maze[nr][nc] = '+'; 
                        q.push({nr, nc});
                }

            }
            }

           

           

            
                
                

                   

                    
            
        }



        

        return -1;
       

    }
};