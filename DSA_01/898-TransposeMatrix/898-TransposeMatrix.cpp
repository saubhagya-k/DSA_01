// Last updated: 05/08/2026, 16:55:18
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