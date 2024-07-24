/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int data;
 *     ListNode *next;
 *     ListNode() : data(0), next(nullptr) {}
 *     ListNode(int x) : data(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : data(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve (ListNode*first,ListNode*second)
{

    //if only one element is present in first list
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }
    ListNode *curr1=first;
   ListNode *next1=curr1->next;
    ListNode *curr2=second;
   ListNode *next2=curr2->next;
    while(next1!=NULL && curr2!=NULL)
    {
         if((curr1->val<=curr2->val) && (next1->val>=curr2->val))
         {
             //NODE ADDITION
             curr1->next=curr2;
             next2=curr2->next;
              curr2->next=next1;
             //UPDATE POINTERS
             curr1=curr2;
             curr2=next2;
         }
         else
         {
             curr1=next1;
             next1=next1->next;

             if(next1==NULL)
             {
                 curr1->next=curr2;
                 return first;
             }
         }
    }
    return first;
}
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first==NULL)
      return second;
    if(second==NULL)
      return first;
  ListNode *temp=NULL;
  ListNode *prev=NULL;
   ListNode *curr=NULL;
      if(first->val<=second->val)
        return solve(first,second);
   
   else
       return solve(second,first);
    }
};