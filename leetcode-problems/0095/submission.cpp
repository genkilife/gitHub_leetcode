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
    vector<TreeNode*> generateTreesWithoffset(int n, int offset) {
        vector<TreeNode*> ans;
        if(n==0){
            return ans;
        } 
        TreeNode* head = new TreeNode(n+offset);
        if (n==1){

            ans.push_back(head);
            return ans;
        }
        

            //int sum = 0;
            for(int left=0; left<=(n-1); left++){
                int right = (n-1)-left;
                //sum += ans[left] * ans[right];
                
                vector<TreeNode*> left_tree = generateTreesWithoffset(left,offset);
                vector<TreeNode*> right_tree = generateTreesWithoffset(right,offset+left+1);
                
                for(int idx_l =0; idx_l <= left_tree.size(); idx_l++){
                    TreeNode* left_node;
                    TreeNode* right_node;
                    if(left_tree.size() == 0){
                        left_node = NULL;
                    } else if(idx_l == left_tree.size()){
                        break;
                    } else{
                        left_node = left_tree[idx_l];
                    }
                    //cout <<"access generate: "<<n<<" left node index: "<< idx_l<<endl;
                    
                    for(int idx_r =0; idx_r <= right_tree.size(); idx_r++){
                        if(right_tree.size() == 0){
                            right_node = NULL;
                        } else if(idx_r == right_tree.size()){
                            break;
                        } else {
                            right_node = right_tree[idx_r];
                        }
                        //cout <<"access generate: "<<n<<" right node index: "<< idx_r<<endl;
                        TreeNode* top= new TreeNode(left+1+offset);
                        top->left = left_node;
                        top->right = right_node;
                        ans.push_back(top);
                        
                    }
                    
                }
            }
            //ans[i] = sum;
        //cout <<"return generate: "<<n<<" ans size "<< ans.size()<<endl;
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return generateTreesWithoffset(n,0);

    }
};
