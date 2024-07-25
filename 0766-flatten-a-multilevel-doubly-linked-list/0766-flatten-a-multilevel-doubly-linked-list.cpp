/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        Node* itr=NULL;
        while(curr!=NULL){

            while(curr->child==NULL && curr->next!=NULL){
                curr=curr->next;
            }
            itr=curr->child;
            while(itr!=NULL && itr->next!=NULL)
                itr=itr->next;
            if(itr){
                itr->next = curr->next;
                curr->child->prev=curr;}
            if(curr->next!=NULL)
                curr->next->prev=itr;
            curr->next = curr->child;
            curr->child = NULL;
            curr=curr->next;
        }
        return head;
    }
};