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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* head1=reverseList(head->next);
        head->next->next = head; 
        head->next = NULL;
        return head1;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* head1 = reverseList(head);
        ListNode* itr=head1;
        int ans=0;
        int count=0;
        while(itr!=NULL){
            ans+= itr->val* pow(2,count);
            count++;
            itr=itr->next;
        }
        return ans;
    }
};