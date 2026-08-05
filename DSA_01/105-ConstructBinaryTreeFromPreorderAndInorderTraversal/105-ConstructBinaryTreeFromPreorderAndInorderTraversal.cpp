// Last updated: 05/08/2026, 17:01:23
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> idx;
    for (int i = 0; i < inorder.size(); i++)
        idx[inorder[i]] = i;

    function<TreeNode*(int, int, int, int)> build = [&](int preL, int preR, int inL, int inR) -> TreeNode* {
        if (preL > preR) return nullptr;

        int rootVal = preorder[preL];
        int mid = idx[rootVal];
        int leftSize = mid - inL;

        TreeNode* root = new TreeNode(rootVal);
        root->left  = build(preL + 1, preL + leftSize, inL, mid - 1);
        root->right = build(preL + leftSize + 1, preR, mid + 1, inR);
        return root;
    };

    return build(0, preorder.size() - 1, 0, inorder.size() - 1);
}
};