// Last updated: 23/08/2026, 18:29:06
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int n;
    int m;
    vector<string> result;

    struct triNode {
        bool endWord;
        string word;
        triNode* children[26];
    };

    triNode* getNode() {
        triNode* newNode = new triNode();
        newNode->endWord = false;
        newNode->word = "";
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(triNode* root, string& word) {
        triNode* crawler = root;
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if(crawler->children[ch - 'a'] == NULL) {
                crawler->children[ch - 'a'] = getNode();
            }
            crawler = crawler->children[ch - 'a'];
        }
        crawler->endWord = true;
        crawler->word = word;
    }

    // Direction vectors for 4-directional movement (Up, Down, Left, Right)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int i, int j, triNode* root) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        
        char ch = board[i][j];
        if(ch == '$' || root->children[ch - 'a'] == NULL) {
            return;
        }

        root = root->children[ch - 'a'];
        if(root->endWord) {
            result.push_back(root->word);
            root->endWord = false; // Prevent duplicate additions of the same word
        }

        // Mark as visited
        board[i][j] = '$';

        // Traverse in 4 directions using the direction vectors
        for(int d = 0; d < 4; d++) {
            int nextI = i + dx[d];
            int nextJ = j + dy[d];
            dfs(board, nextI, nextJ, root);
        }

        // Backtrack and restore character
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        if (n == 0) return result;
        m = board[0].size();

        triNode* root = getNode();
        for(string &word : words) {
            insert(root, word);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char ch = board[i][j];
                if(root->children[ch - 'a'] != NULL) {
                    dfs(board, i, j, root);
                }
            }
        }

       

        return result;
    }
};
