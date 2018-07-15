/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverser(ListNode* head, ListNode* & new_head, ListNode* end){
        if(head->next == end){
            new_head = head;
            return head;
        } else{
            ListNode* tmp = reverser(head->next, new_head, end);
            tmp->next = head;
            return head;
        }
    }
    
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 0;
        if(m==n){
            return head;
        }
        ListNode* new_h;
        

        
        ListNode* lh;
        ListNode* ln;
        ListNode* rn;
        
        ListNode* my_head = new ListNode(0);
        my_head->next = head;
        
        ListNode* iter = my_head;

        count = 0;
        while(iter != NULL){
            if((count+1) ==m ){
                lh = iter;
                ln = iter->next;
            }
                
            if(count == n){
                rn = iter->next;
            }
                
            iter = iter->next;
            count+=1;
        }

        ListNode* lastnode = reverser(ln, new_h, rn);
        lastnode->next = rn;
        lh->next = new_h;
        

        
        return  my_head->next;
        
    }
};
