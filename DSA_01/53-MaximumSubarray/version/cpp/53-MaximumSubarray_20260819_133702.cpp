// Last updated: 19/08/2026, 13:37:02
1class Solution {
2public:
3    bool searchMatrix(vector<vector<int>>& matrix, int target) {
4
5        int n = matrix.size(); //rows
6        int m = matrix[0].size(); //column
7
8        int row = 0;
9        int col = m - 1;
10
11         while (row < n && col >= 0) {
12
13             int current = matrix[row][col];
14
15            if (current == target) {
16                return true;
17
18            }
19
20
21            if(current > target){
22
23                col--;
24
25            }
26
27            else{
28                row++;
29            }
30
31
32         }
33
34         return false;
35        
36    }
37};