// Last updated: 24/09/2026, 08:20:21
1class Solution {
2public:
3
4
5bool isValid(vector<vector<char>>& board,int row,int col,int num){
6
7    int start_row = (row/3) * 3;
8    int start_col = (col/3) * 3;
9
10
11
12
13    for(int i=0;i<9;++i){
14
15        if(board[row][i]==num){
16            return false;
17        }
18
19        if(board[i][col] == num){
20            return false;
21        }
22
23        if (board[start_row + (i / 3)][start_col + (i % 3)] == num) return false;
24
25
26    }
27
28    return true;
29
30}
31
32bool solve(vector<vector<char>>& board){
33    int n = board.size();
34        int m = board[0].size();
35
36        for(int row=0;row<n;row++){
37            for(int col=0;col<m;col++){
38
39                if(board[row][col] == '.'){
40                    for(int num='1';num<='9';++num){
41                        if(isValid(board,row,col,num)){
42                            board[row][col] = num;
43
44
45                            if(solve(board)){
46                                return true;
47                            }
48
49                            board[row][col] = '.';
50                        }
51                    }
52
53                      return false;
54                
55
56              
57            }
58        }
59        
60    }
61
62    return true;
63}
64void solveSudoku(vector<vector<char>>& board) {
65
66        solve(board);
67}
68
69};