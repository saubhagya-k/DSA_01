// Last updated: 22/08/2026, 11:51:27
1#include <vector>
2#include <string>
3
4using namespace std;
5
6class Solution {
7public:
8    int n;
9    int m;
10    vector<string> result;
11
12    struct triNode {
13        bool endWord;
14        string word;
15        triNode* children[26];
16    };
17
18    triNode* getNode() {
19        triNode* newNode = new triNode();
20        newNode->endWord = false;
21        newNode->word = "";
22        for(int i = 0; i < 26; i++) {
23            newNode->children[i] = NULL;
24        }
25        return newNode;
26    }
27
28    void insert(triNode* root, string& word) {
29        triNode* crawler = root;
30        for(int i = 0; i < word.length(); i++) {
31            char ch = word[i];
32            if(crawler->children[ch - 'a'] == NULL) {
33                crawler->children[ch - 'a'] = getNode();
34            }
35            crawler = crawler->children[ch - 'a'];
36        }
37        crawler->endWord = true;
38        crawler->word = word;
39    }
40
41    // Direction vectors for 4-directional movement (Up, Down, Left, Right)
42    int dx[4] = {-1, 1, 0, 0};
43    int dy[4] = {0, 0, -1, 1};
44
45    void dfs(vector<vector<char>>& board, int i, int j, triNode* root) {
46        if(i < 0 || i >= n || j < 0 || j >= m) {
47            return;
48        }
49        
50        char ch = board[i][j];
51        if(ch == '$' || root->children[ch - 'a'] == NULL) {
52            return;
53        }
54
55        root = root->children[ch - 'a'];
56        if(root->endWord) {
57            result.push_back(root->word);
58            root->endWord = false; // Prevent duplicate additions of the same word
59        }
60
61        // Mark as visited
62        board[i][j] = '$';
63
64        // Traverse in 4 directions using the direction vectors
65        for(int d = 0; d < 4; d++) {
66            int nextI = i + dx[d];
67            int nextJ = j + dy[d];
68            dfs(board, nextI, nextJ, root);
69        }
70
71        // Backtrack and restore character
72        board[i][j] = ch;
73    }
74
75    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
76        n = board.size();
77        if (n == 0) return result;
78        m = board[0].size();
79
80        triNode* root = getNode();
81        for(string &word : words) {
82            insert(root, word);
83        }
84
85        for(int i = 0; i < n; i++) {
86            for(int j = 0; j < m; j++) {
87                char ch = board[i][j];
88                if(root->children[ch - 'a'] != NULL) {
89                    dfs(board, i, j, root);
90                }
91            }
92        }
93
94       
95
96        return result;
97    }
98};
99