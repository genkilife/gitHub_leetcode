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
    
    int acc(TreeNode* root, bool free, int sum){
        if(root == NULL){
            return sum;
        }
        
        if(free){
            // take
            int a = acc(root->left, !free, sum) + acc(root->right, !free, sum) + root->val;
            // not take
            int b = acc(root->left, free, sum) + acc(root->right, free, sum);
            
            if(a > b){
                return a;
            } else{
                return b;
            }
            
        } else{
            return acc(root->left, !free, sum) + acc(root->right, !free, sum);
            
        }
        
    }
    
    int rob(TreeNode* root) {
        bool free = true;
        if(root == NULL){
            return 0;
        }
        
        
        int a = acc(root, free, 0);
        int b = acc(root->left, !free, 0) + acc(root->right, !free, 0) + root->val;
        
        if(a > b){
            return a;
        } else{
            return b;
        }
         
    }
};
