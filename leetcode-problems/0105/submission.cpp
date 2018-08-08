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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //cout<<"XXXX: "<<preorder.size()<<" "<<inorder.size()<<endl;
        if(preorder.size()==0 && inorder.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int head = preorder[0];
        int pivot = 0;
        for(pivot=0; pivot<inorder.size(); pivot++){
            if(inorder[pivot] == head){
                break;
            }
        }
        
        vector<int> left_in(inorder.begin(), inorder.begin() + pivot);
        vector<int> right_in(inorder.begin() + pivot +1, inorder.end());
        
        //cout<<"insize: "<<left_in.size()<<" "<<right_in.size()<<endl;
        
        vector<int> left_pre(preorder.begin()+1, preorder.begin() + 1 + left_in.size());
        vector<int> right_pre(preorder.begin()+1 + left_in.size(), preorder.end());        
        
        //cout<<"presize: "<<left_pre.size()<<" "<<right_pre.size()<<endl;
        
        root->val = head;
        root->left = buildTree(left_pre, left_in);
        root->right = buildTree(right_pre, right_in);
        
        return root;
        
    }
};
