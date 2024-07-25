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
private:
   ListNode* merge(ListNode* left,ListNode* right)
{
    if(left==NULL)
    {
        return right;
    }
    if(right==NULL)
    {
        return left;
    }
    ListNode* ans=new ListNode(-1);
    ListNode* temp=ans;
    while(left!=NULL && right!=NULL)
    {
        if(left->val < right->val)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    //because ans is on dummy node
    ans=ans->next;
    return ans;
}
ListNode* findmid(ListNode* head)
{
   ListNode* slow=head;
   ListNode* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
public:
    ListNode* sortList(ListNode* head) {
         //base case
   if(head==NULL || head->next==NULL)
        return head;
    //Finding mid
    ListNode* mid=findmid(head);
    
    //linked list in 2 parts
   ListNode* left=head;
    ListNode* right=mid->next;
    mid->next=NULL;
    //recursive call
    left=sortList(left);
    right=sortList(right);
    //merge two linkedlist
   ListNode* result=merge(left,right);
    return result;
    }
};