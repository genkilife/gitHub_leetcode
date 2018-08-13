/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse_l(TreeNode* root, vector<TreeNode*> &list){
    list.push_back(root);
    if(root == NULL){
        return;
    }
    traverse_l(root->left, list);
    traverse_l(root->right, list);
    return;
}
void traverse_r(TreeNode* root, vector<TreeNode*> &list){
    list.push_back(root);
    if(root == NULL){
        return;
    }
    traverse_r(root->right, list);
    traverse_r(root->left, list);
    return;
}


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> list_l, list_r;
        traverse_l(root, list_l);
        traverse_r(root, list_r);
        
        for(int i=0; i<list_l.size(); i++){
            if(i >= list_r.size()){
                return false;
            }
            if(list_l[i] != NULL){
                if(list_r[i] == NULL || list_l[i]->val != list_r[i]->val){
                    return false;
                }
            } else if(list_r[i]!=NULL){
                return false;
            }

        }
        return true;
        
        
    }
};
