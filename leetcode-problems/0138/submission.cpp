/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

    int compute_level(RandomListNode* head, RandomListNode* target, int level){
        if(head != target){
            return compute_level(head->next, target, level+1);
        }
        return level;
    }
    void write_random(RandomListNode* traverse, RandomListNode* copy, int level){
        if(level != 0){
            write_random(traverse->next, copy, level-1);
        } else{
            copy->random = traverse;
        }
        return;
    }
    void process_next(RandomListNode* orig, RandomListNode* copied){
        if(orig->next != NULL){
            copied->next = new RandomListNode(orig->next->label);
            process_next(orig->next, copied->next);
        }
        return;
    }
    void process_random(RandomListNode* orig, RandomListNode* copied, RandomListNode* orig_root, RandomListNode* copied_root){
        if(orig != NULL){
            if(orig->random != NULL){
                // find level
                int level = compute_level(orig_root, orig->random, 0);
                write_random(copied_root, copied, level);
            }
            process_random(orig->next, copied->next, orig_root, copied_root);
        }
        return;
    }


    void print_list(RandomListNode *head, RandomListNode *root){
        if(head != NULL){
            cout<<head->label<<" ";
            if(head->random != NULL){
                cout<<compute_level(root, head->random, 0)<<" "<<endl;
            } else{
                cout<<"NULL"<<endl;
            }
            print_list(head->next, root);
        }
        return;
    }
class Solution {
public:

    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL){
            return NULL;
        }
        /*
        cout<<"case: "<<endl;
        print_list(head, head);
        */
        
        RandomListNode * copy = NULL;
        
        copy = new RandomListNode(head->label);
        // create next
        process_next(head, copy);
        
        process_random(head, copy, head, copy);
        /*
        cout<<"copy case:"<<endl;
        print_list(copy, copy);
        */
        return copy;
        
    }
};
