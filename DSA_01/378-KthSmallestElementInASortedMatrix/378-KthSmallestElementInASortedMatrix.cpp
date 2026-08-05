// Last updated: 05/08/2026, 16:57:49
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int r = matrix.size();
        int c = matrix[0].size();
        

        vector<int>final;

        for(int i=0;i<r;i++){
            for(int j = 0;j<c;j++){
                final.push_back(matrix[i][j]);
            }
        }

        sort(final.begin(),final.end());

       return final[k-1];
    }
};