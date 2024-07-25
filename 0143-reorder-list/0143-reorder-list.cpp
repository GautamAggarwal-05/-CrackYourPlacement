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
ListNode *reverse(ListNode *head)
{
    ListNode *prev = NULL;	
    ListNode *curr = head;
    ListNode *forward = head;
    while (forward != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *head = head1;
    ListNode *temp1 = head1->next;
    ListNode *temp2 = head2->next;
    while (head1 != NULL && head2 != NULL)
    {
        head1->next = head2;
        head2->next = temp1;
        head2 = temp2;
        head1 = temp1;
        if (temp1 != NULL)
            	temp1 = temp1->next;
        if (temp2 != NULL)
            	temp2 = temp2->next;
    }
    return head;
}

public:
    void reorderList(ListNode* head) {
    if (head == NULL || (head)->next == NULL)
    {
        	return;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head2 = slow->next;
    slow->next = NULL;
    head2 = reverse(head2);
    ListNode *mergedHead = merge(head, head2);
    head = mergedHead;
    }
};