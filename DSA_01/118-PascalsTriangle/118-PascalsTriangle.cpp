// Last updated: 05/08/2026, 17:00:57
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Create a row with (i + 1) elements initialized to 1
            vector<int> row(i + 1, 1);

            // Fill in the middle elements (if any)
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            triangle.push_back(row);  // Add the row to the triangle
        }

        return triangle;
    }
};
