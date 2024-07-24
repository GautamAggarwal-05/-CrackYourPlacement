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
    void reverse(ListNode** mid)
    {
         ListNode* prev=NULL;
          ListNode* curr=*mid;
           ListNode* forward=curr;
           while(curr!=NULL)
           {
               forward=forward->next;
               curr->next=prev;
               prev=curr;
               curr=forward;
           }
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
          return true;
        ListNode* f=head;
        ListNode* l=head;
        int len=1;
        while(l->next!=NULL)
        {
            l=l->next;
            len++;
        }
        ListNode* mid=head;
        int m,n;
         m=n=len/2;
        while(n!=0)
        { 
           mid= mid->next;
            n--;
        }
        if(mid->next!=NULL)
           reverse(&mid);
        while(m!=0)
        {
            m--;
            if(f->val!=l->val)
              return false;
            f=f->next;
            l=l->next;
        }
        return true;
    }
};