// Last updated: 05/08/2026, 16:57:10
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        vector<int> ans;

        for (int sum = 0; sum <= r + c - 2; sum++) {

            vector<int> diagonal;

            for (int row = 0; row < r; row++) {

                int col = sum - row;

                if (col >= 0 && col < c) {
                    diagonal.push_back(mat[row][col]);
                }
            }

            if (sum % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }

            for (int x : diagonal) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};