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
    void deleteNode(ListNode* node) {
        if(node == NULL)   return;
        // if that's the last node
        if(node->next == NULL){
            delete node;
            node = NULL;
        }else{
            ListNode *p = node->next;
            node->val = p->val;
            node->next = p->next;
            delete p;
        }
    }
};