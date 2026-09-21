// Last updated: 21/09/2026, 16:43:03
1class Solution {
2public:
3    int n, m;
4    vector<vector<int>> direction{{1,0}, {-1,0}, {0,1}, {0,-1}};
5
6    bool helper(int i, int j, int idx, vector<vector<char>>& board, string& word) {
7        // Success case: The entire word has been matched
8        if (idx == word.size()) {
9            return true;
10        }
11
12        // Out of bounds check
13        if (i < 0 || j < 0 || i >= n || j >= m) {
14            return false;
15        }
16
17        // Mismatch or already visited check
18        if (board[i][j] != word[idx] || board[i][j] == '$') {
19            return false;
20        }
21
22        // Backtracking: Mark current cell as visited
23        char temp = board[i][j];
24        board[i][j] = '$';
25
26        // Explore all 4 neighbors
27        for (auto& dir : direction) {
28            int new_i = i + dir[0];
29            int new_j = j + dir[1];
30            
31            if (helper(new_i, new_j, idx + 1, board, word))
32                return true;
33        }
34
35        // Backtracking: Restore original character
36        board[i][j] = temp;
37        return false;
38    }
39
40    bool exist(vector<vector<char>>& board, string word) {
41        n = board.size();     // rows
42        m = board[0].size();  // columns
43
44        // --- OPTIMIZATION TO PREVENT TLE ---
45        int board_counts[128] = {0};
46        int word_counts[128] = {0};
47        
48        // 1. Count frequencies on the board
49        for (int i = 0; i < n; i++) {
50            for (int j = 0; j < m; j++) {
51                board_counts[board[i][j]]++;
52            }
53        }
54        
55        // 2. Count frequencies required by the word
56        for (char c : word) {
57            word_counts[c]++;
58        }
59        
60        // Pruning Check 1: If the board lacks enough characters, return false immediately
61        for (int i = 0; i < 128; i++) {
62            if (board_counts[i] < word_counts[i]) {
63                return false;
64            }
65        }
66        
67        // Pruning Check 2: Word Reversal Trick
68        // If the tail character is rarer than the head character, reverse the word 
69        // to minimize the backtracking branches right from the start.
70        if (board_counts[word.back()] < board_counts[word.front()]) {
71            reverse(word.begin(), word.end());
72        }
73        // ------------------------------------
74
75        // Main search loops
76        for (int i = 0; i < n; i++) {
77            for (int j = 0; j < m; j++) {
78                if (board[i][j] == word[0] && helper(i, j, 0, board, word)) {
79                    return true;
80                }
81            }
82        }
83
84        return false;
85    }
86};
87