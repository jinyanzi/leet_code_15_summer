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
        
        
        ListNode *p = NULL, *new_head = NULL;
        while(head->next){
            ListNode *tail = head, *prev = head;
            // first look for the tail and the one before tail
            while(tail->next != NULL){
                prev = tail;
                tail = tail->next;
            }
            
            prev->next = NULL;  // ! IMPORTANT
            // if this this the first iteration, remember the tail as new head
            if(p == NULL){
                new_head = tail;
                p = tail;
            }else{
                // solve iteratively
                p->next = tail;
                p = p->next;    // append new tail
            }
        }
        
        // append the head to the tail of the new list
        p->next = head;
        
        return new_head;
    }
};