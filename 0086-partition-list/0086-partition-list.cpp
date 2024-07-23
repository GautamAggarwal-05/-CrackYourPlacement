/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy= new ListNode(0);
        ListNode* greater_prev=dummy;
        dummy->next=head;
        ListNode* greater=head;
        while(greater!=NULL && greater->val < x){
            greater_prev = greater;
            greater=greater->next;
        }
        ListNode* itr=greater;
        while(itr!=NULL && itr->next!=NULL){
            if(itr->next->val < x){
                greater_prev->next = itr->next;
                greater_prev = greater_prev->next;
                itr->next = itr->next->next;
            }
            else{
                itr=itr->next;
            }
        }
        greater_prev->next = greater;
        return dummy->next;
    }
};