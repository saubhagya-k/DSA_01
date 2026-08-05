// Last updated: 05/08/2026, 17:02:41
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();
    int n = matrix[0].size();
  
    
    vector<vector<int>> res(n, vector<int>(m));
  
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[j][m - i - 1] = matrix[i][j];
        }
    }
    matrix =  res;

        
    }
};