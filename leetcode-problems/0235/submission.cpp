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
    bool find_single(TreeNode* root, TreeNode* p){
        if(root == NULL){
            return false;
        }
        if(root == p){
            return true;
        }
        
        bool find = false;
        if(root->left != NULL){
            find = find_single(root->left, p);
            if(find){
                return true;
            }
        }
        if(root->right != NULL){
            find = find_single(root->right, p);
            if(find){
                return true;
            }
        }
        return false;
    }
    
    bool process(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(ans != NULL){
            return false;
        }
        
        bool find_p=false;
        if(root == p){
            find_p = true;
        }
        bool find_q=false;
        if(root == q){
            find_q = true;
        }
        
        
        if(root->left != NULL){
            process(root->left, p, q, ans);
            if(ans != NULL){
                return false;
            }
            if(!find_p){
                find_p = find_single(root->left, p);
            }
            if(!find_q){
                find_q = find_single(root->left, q);
            }
        }
        if(root->right != NULL){
            process(root->right, p, q, ans);
            if(ans != NULL){
                return false;
            }
            if(!find_p){
                find_p = find_single(root->right, p);
            }
            if(!find_q){
                find_q = find_single(root->right, q);
            }
        }
        
        
        if(find_p && find_q){
            ans = root;
        }
        
        
        return false;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        
        
        TreeNode* ans = NULL;
        
        process(root, p, q, ans);

        return ans;
    }
};
