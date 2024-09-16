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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len=0;
        ListNode* itr = head;
        while(itr!=NULL){
            len++;
            if(itr->next==NULL){
                itr->next=head;
                break;
            }
            itr=itr->next;
        }
        k=k%len;
        int i=0;
        ListNode *itr1=head;
        while(i<len-k-1){
            itr1=itr1->next;
            i++;
        }
        head = itr1->next;
        itr1->next=NULL;
        return head;
    }
};