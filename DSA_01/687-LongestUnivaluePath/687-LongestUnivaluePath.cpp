// Last updated: 01/09/2026, 23:17:52

class Solution {
public:

int maxCount = 0;

int dfs(TreeNode* node){

    if(node == NULL){
        return 0;
    }

    int leftChild = dfs(node->left);
    int rightChild = dfs(node->right);

    int leftCount = 0;
    int rightCount = 0;

    if(node->left!=NULL && node->left->val == node->val){
        leftCount = leftChild+1;
    }

      if(node->right!=NULL && node->right->val == node->val){
        rightCount = rightChild+1;
    }

    maxCount = max(maxCount,leftCount+rightCount);

  return max(leftCount, rightCount);


}
    int longestUnivaluePath(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

      dfs(root);

        return maxCount;
        
    }
};