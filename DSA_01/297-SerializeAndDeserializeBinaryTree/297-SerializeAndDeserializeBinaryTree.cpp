// Last updated: 27/08/2026, 12:54:36
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

void help(TreeNode* node,string& res){

    if(node == NULL){
        res += "#,";
        return;
    }

    res+=(to_string(node->val)+",");

    help(node->left,res);
    help(node->right,res);



}

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string res= "";

         help(root,res);

         return res;
        
    }

    TreeNode* deserializeHelper(stringstream& ss) {

         string value;

    if (!getline(ss, value, ',')) {
        return NULL;
    }

    if (value == "#") {
        return NULL;
    }

    TreeNode*root = new TreeNode(stoi(value));

    root->left = deserializeHelper(ss);
    root->right = deserializeHelper(ss);

    return root;




    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string res) {

        stringstream ss(res);

        return deserializeHelper(ss);



    }
        
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));