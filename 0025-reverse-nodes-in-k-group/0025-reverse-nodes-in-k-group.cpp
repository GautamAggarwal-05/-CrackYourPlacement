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
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;

        while(curr!=NULL){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* getNode(ListNode* temp,int k){
        for(int i=1;temp!=NULL && i<k;i++){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        ListNode* nextNode=NULL;

        while(temp!=NULL){
            ListNode* kthnode = getNode(temp,k);
            if(kthnode==NULL){
                if(prevNode)
                    prevNode->next=temp;
                break;
            }
            nextNode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            if(temp==head){//firstGroup;
                head=kthnode;
            }
            else{
                prevNode->next=kthnode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};