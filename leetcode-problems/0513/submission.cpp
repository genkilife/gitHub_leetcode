/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void DFS(TreeNode* root,int& cur, int& left_level, int level){
        if(root->left != NULL){
            if(level > left_level){
                cur = root->left->val;
                left_level = level;
            }
            DFS(root->left, cur, left_level, level+1);
        }
        if(root->right != NULL){
            if(level > left_level){
                cur = root->right->val;
                left_level = level;
            }
            DFS(root->right, cur, left_level, level+1);
        }
        return;
    }
    
    int findBottomLeftValue(TreeNode* root) {

        int cur = root->val;
        int left_level = 0;
        DFS(root, cur, left_level, 1);
        
        return cur;
        
    }
};
