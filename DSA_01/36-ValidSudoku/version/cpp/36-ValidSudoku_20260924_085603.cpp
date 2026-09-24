// Last updated: 24/09/2026, 08:56:03
1class Solution {
2public:
3
4bool isValid(vector<vector<char>>& board,int row,int col, int num){
5
6    int start_row = (row/3)*3;
7    int start_col = (col/3)*3;
8
9
10    for(int i=0;i<9;i++){
11        if(i!=col && board[row][i] == num) return false;
12
13        if(i!=row && board[i][col] == num) return false;
14    }
15
16    for(int k=0;k<3;k++){
17        for(int l=0;l<3;l++){
18           int curr_row = start_row + k;
19            int curr_col = start_col + l;
20
21            if(curr_row==row && curr_col==col)continue;
22
23            if (board[curr_row][curr_col] == num) {
24                    return false;
25                }
26        }
27    }
28
29    return true;
30
31
32}
33    bool isValidSudoku(vector<vector<char>>& board) {
34
35        int n = board.size();
36        int m = board[0].size();
37
38
39        for(int row=0; row<n; row++){
40            for(int col = 0;col<m;col++){
41                if(board[row][col]!='.'){
42
43                    int num = board[row][col];
44
45                    if(!isValid(board,row,col,num)){
46                       return false;
47                    }
48
49                }
50                
51            }
52           
53        }
54
55         return true;
56        
57    }
58   
59};