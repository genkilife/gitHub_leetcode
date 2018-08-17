/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void find(ListNode* root, ListNode* cur, ListNode* pre){
    //cout<<root->val<<" "<<cur->val<<" ";
    //if(pre != NULL){cout<<pre->val<<endl;} else{cout<<endl;}
    while(cur->next != NULL){
        pre = cur;
        cur = cur->next;
    }
    // insert in between 
    if(root->next != NULL && root->next != cur){
        ListNode* nxt_root = root->next;
        root->next = cur;
        cur->next = nxt_root;
        pre->next = NULL;
        find(nxt_root, nxt_root, pre->next);
    }   
    return;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL){
            return;
        }
        ListNode* cur =NULL;
        find(head, head, cur);
        return;
    }
};
