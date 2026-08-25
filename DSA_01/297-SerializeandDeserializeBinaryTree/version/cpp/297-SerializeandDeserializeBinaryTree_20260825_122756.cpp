// Last updated: 25/08/2026, 12:27:56
// good question
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13void help(TreeNode* node,string& res){
14
15    if(node == NULL){
16        res += "#,";
17        return;
18    }
19
20    res+=(to_string(node->val)+",");
21
22    help(node->left,res);
23    help(node->right,res);
24
25
26
27}
28
29    // Encodes a tree to a single string.
30    string serialize(TreeNode* root) {
31
32        string res= "";
33
34         help(root,res);
35
36         return res;
37        
38    }
39
40    TreeNode* deserializeHelper(stringstream& ss) {
41
42         string value;
43
44    if (!getline(ss, value, ',')) {
45        return NULL;
46    }
47
48    if (value == "#") {
49        return NULL;
50    }
51
52    TreeNode*root = new TreeNode(stoi(value));
53
54    root->left = deserializeHelper(ss);
55    root->right = deserializeHelper(ss);
56
57    return root;
58
59
60
61
62    }
63
64    // Decodes your encoded data to tree.
65    TreeNode* deserialize(string res) {
66
67        stringstream ss(res);
68
69        return deserializeHelper(ss);
70
71
72
73    }
74        
75    
76};
77
78// Your Codec object will be instantiated and called as such:
79// Codec ser, deser;
80// TreeNode* ans = deser.deserialize(ser.serialize(root));