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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if anyone is NULL, return
        if(!headA || !headB)    return NULL;
        
        ListNode *a = headA, *b = headB;
        // the idea is keep iterate from head to tail repeated
        // if A and B has the same length, we may have result in one scan
        // otherwise the two pointer will finally meet
        while(1){
            // A and B have the same length without intersection
            if(a == b && !a)  return NULL;
            
            // A and B have intersection
            if( a == b && a)    return a;
            
            // if any of the two pointer reaches tail, go back to head
            // otherwise, go to next node
            a = (a ? a->next : headA);
            b = (b ? b->next : headB);
        }
    }
};