// Last updated: 05/08/2026, 16:53:14
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {


        int n = mat.size();
        int m = mat[0].size();

        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( i==j){

                    sum += mat[i][j];

                }
            }


        }


        int j = m-1;


        for(int i=0;i<n;i++){
            

                if( j>-1){
                    sum += mat[i][j];

                    j--;

                }



            }
            if(n % 2 != 0){

            sum = sum-mat[n/2][m/2];
            }

            return sum;
        
        
    }
};