// Last updated: 05/08/2026, 17:01:48
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
        if (!head || left == right) return head;

        ListNode* dummyN = new ListNode(-1, head);
        ListNode* temp = dummyN;

        // Move to the node before left position
        for (int i = 1; i < left; i++) {
            temp = temp->next;
        }

        ListNode* curr = temp->next;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        
        // Reverse the sublist from left to right
        for (int i = 0; i < right - left + 1; i++) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        // Reconnect the reversed portion
        temp->next->next = curr;  // Connect the tail of reversed list to remaining
        temp->next = prev;        // Connect the head of reversed list

        return dummyN->next;
    }
};