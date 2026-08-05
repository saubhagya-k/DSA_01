// Last updated: 05/08/2026, 17:01:42
class Solution {
public:
    bool validate(TreeNode* node, long min, long max){
        
        if(node == NULL) return true;

        
        if(node->val <= min || node->val >= max)
            return false;

        
        return validate(node->left,  min, node->val)  &&
               validate(node->right, node->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};