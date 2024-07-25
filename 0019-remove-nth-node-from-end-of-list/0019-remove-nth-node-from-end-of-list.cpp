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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* itr=head;
        while(itr!=NULL)
        {
            len++;
            itr=itr->next;
        }
        if(len-n-1==-1)
            return head->next;
        itr=head;
        for(int i=0;i<len-n-1;i++)
        {
            itr=itr->next;
        }
        
            itr->next=itr->next->next;
            return head;
    }
};