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
    int level(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = level(root->left)+1;
        int right = level(root->right)+1;
        
        if(left > right){
            return left;
        } else{
            return right;
        }
        
    }
    
    int visit(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        
        int left = level(root->left);
        int right = level(root->right);

        int ans = left+right;
        
        int left_a = visit(root->left);
        if(ans<left_a){
            ans = left_a;
        }
        
        int right_a = visit(root->right);
        if(ans<right_a){
            ans=right_a;
        }
        //cout<<ans<<" "<<left_a<<" "<<right_a<<endl;
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {        
        return visit(root);
        
    }
};
