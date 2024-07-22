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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if left is equal to right, no reversal needed
        if (left == right) return head;
        
        // Create a dummy node to handle edge cases more easily
        ListNode dummy(0);
        dummy.next = head;
        
        // Find the node just before the left position
        ListNode* left_prev = &dummy;
        for (int i = 1; i < left; ++i) {
            left_prev = left_prev->next;
        }
        
        // Reverse the sublist from left to right
        ListNode* curr = left_prev->next;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for (int i = left; i <= right; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Connect the reversed sublist back to the original list
        left_prev->next->next = curr;
        left_prev->next = prev;
        
        // Return the new head
        return dummy.next;
    }
};
