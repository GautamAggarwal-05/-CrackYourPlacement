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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*>s;
        ListNode* itr=head;
        ListNode* anshead=NULL;
        while(itr!=NULL)
        {
            if(s.empty()){
                s.push(itr);
                itr=itr->next;
            }
            else{
                while(!s.empty() && s.top()->val < itr->val)
                {
                    s.pop();
                }
                s.push(itr);
                itr=itr->next;
            }
        }

        while(!s.empty())
        {
            ListNode *top=s.top();
            s.pop();
            if(anshead==NULL)
                anshead=top;
            else{
                top->next=anshead;
                anshead=top;
            }
        }

        return anshead;
    }
};