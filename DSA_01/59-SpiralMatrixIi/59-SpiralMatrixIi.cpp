// Last updated: 05/08/2026, 17:02:27
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>final(n,vector<int>(n));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;

        int num = 1;


        while(top<=bottom && left<=right){

            for(int i=left;i<=right;i++){
                final[top][i] = num++;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                final[i][right] = num++;
            }
            right--;



            if(top<=bottom){
                for(int i=right;i>=left;i--){
                final[bottom][i] = num++;
            }
            bottom--;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    final[i][left] = num++;
                }
                left++;
            }


            
        }
        return final;

        
    }
};