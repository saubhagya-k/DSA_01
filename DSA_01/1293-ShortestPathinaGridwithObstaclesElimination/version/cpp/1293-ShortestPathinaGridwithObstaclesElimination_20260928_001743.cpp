// Last updated: 28/09/2026, 00:17:43
1class Solution {
2public:
3    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
4
5        int n = matrix.size();
6        int m = matrix[0].size();
7
8
9        for(int i=1;i<n;i++){
10            for(int j=1;j<m;j++){
11                if(matrix[i][j]!=matrix[i-1][j-1]){
12                    return false;
13                }
14            }
15        }
16
17        return true;
18
19        
20    }
21};