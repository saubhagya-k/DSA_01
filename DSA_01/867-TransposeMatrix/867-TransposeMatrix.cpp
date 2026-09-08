// Last updated: 08/09/2026, 12:47:25
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int n = matrix.size();

        int m = matrix[0].size();

        vector<vector<int>>newOne(m,vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                newOne[j][i] = matrix[i][j];

            }
        }
        matrix = newOne;

        return matrix;
        
    }
};