/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int traverse(TreeNode* root, int base){
    if(root == NULL){
        return base;
    }
    int right =traverse(root->right, base);
    
    root->val += right;
    return traverse(root->left, root->val);
}
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        int right = traverse(root->right, 0);
        
        root->val += right;
        
        traverse(root->left, root->val);
        
        return root;
    }
};
