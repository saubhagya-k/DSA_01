// Last updated: 05/08/2026, 16:56:43
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>bauna(r,vector<int>(c));

        if(m*n == r*c){

            int idx = 0;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                    bauna[idx/c][idx%c] = mat[i][j];

                    idx++;

                }
            }

            return bauna;

        }

        else{
            return mat;
        }
        
    }
};