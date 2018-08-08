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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //cout<<"XXXX: "<<preorder.size()<<" "<<inorder.size()<<endl;
        if(postorder.size()==0 && inorder.size() == 0){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int head = postorder[postorder.size()-1];
        int pivot = 0;
        for(pivot=0; pivot<inorder.size(); pivot++){
            if(inorder[pivot] == head){
                break;
            }
        }
        
        vector<int> left_in(inorder.begin(), inorder.begin() + pivot);
        vector<int> right_in(inorder.begin() + pivot +1, inorder.end());
        
        //cout<<"insize: "<<left_in.size()<<" "<<right_in.size()<<endl;
        
        vector<int> left_post(postorder.begin(), postorder.begin() + left_in.size());
        vector<int> right_post(postorder.begin() + left_in.size(), postorder.end()-1);        
        
        //cout<<"presize: "<<left_pre.size()<<" "<<right_pre.size()<<endl;
        
        root->val = head;
        root->left = buildTree(left_in, left_post);
        root->right = buildTree(right_in, right_post);
        
        return root;
    }
};
