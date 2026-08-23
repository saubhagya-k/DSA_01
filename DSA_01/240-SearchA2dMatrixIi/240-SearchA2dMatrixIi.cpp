// Last updated: 23/08/2026, 18:28:53
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size(); //rows
        int m = matrix[0].size(); //column

        int row = 0;
        int col = m - 1;

         while (row < n && col >= 0) {

             int current = matrix[row][col];

            if (current == target) {
                return true;

            }


            if(current > target){

                col--;

            }

            else{
                row++;
            }


         }

         return false;
        
    }
};