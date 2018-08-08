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
    void myprint(TreeNode* root, string& output){
        output += to_string(root->val);
        if(root->left != NULL){
            output += '(';
            myprint(root->left, output);
            output += ')';
        } else if (root->right != NULL){
            output += "()";
        }
        if(root->right != NULL){
            output += '(';
            myprint(root->right, output);
            output += ')';
        }
        return;
    }
    
    string tree2str(TreeNode* t) {
        string output;
        if(t == NULL){
            return output;
        }
        
        myprint(t, output);
        
        return output;
        
    }
};
