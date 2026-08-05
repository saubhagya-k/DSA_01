// Last updated: 05/08/2026, 16:51:24
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

     

        int n = matrix.size();
           vector<int>result(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                result[i] += matrix[i][j];

                    
                
            }
        }
    return result;

        
        
    }
};