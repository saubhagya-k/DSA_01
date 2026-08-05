// Last updated: 05/08/2026, 16:55:59
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        

        queue<pair<int,int>>q;
        int n = image.size();
        int m = image[0].size();

       

        int prev_color = image[sr][sc];
        if (prev_color == color) return image;


        image[sr][sc] = color;
        q.push({sr, sc});

        //typical BFS

        int drow[4] = {-1,1,0,0};
        int dcol[4] = {0,0,-1,1};

        while(!q.empty()){

            auto node = q.front();
            q.pop();

            int a = node.first;
            int b = node.second;

            for(int k=0;k<4;k++){
                int nr = a+drow[k];
                int nc = b+dcol[k];

                

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&image[nr][nc] == prev_color){
                    image[nr][nc] = color;

                    q.push({nr,nc});

                }

             
            }




        }
        
                return image;
            
        
    }
};