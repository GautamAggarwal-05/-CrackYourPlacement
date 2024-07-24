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
        ListNode* itrA=headA;
        ListNode* itrB=headB;
        int count=0;
        while(itrA!=itrB ){
            if(!itrA)
                itrA=headB;
            else
                itrA=itrA->next;
            
            if(!itrB)
                itrB=headA;
            else
                itrB=itrB->next;
            }
        return itrA;
        }
};