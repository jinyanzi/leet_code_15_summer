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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        ListNode *tail = head, *prev = head;
        // first look for the tail and the one before tail
        while(tail->next != NULL){
            prev = tail;
            tail = tail->next;
        }
        
        // solve recursively
        prev->next = NULL;  // ! IMPORTANT
        tail->next = reverseList(head);
        
        return tail;
    }
};