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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* p = head;
        ListNode* prev = NULL; 
        while(p){
            // if the value is to be removed
            if(p->val == val){
                if(prev != NULL){   // if not the first node
                    prev->next = p->next;
                    delete p;
                    p = prev->next;
                }else{
                    // delete head node
                    p = p->next;
                    delete head;
                    head = p;
                }
            }else{
                //check next element
                prev = p;
                p = p->next;
            }
        }
        
        return head;
    }
};