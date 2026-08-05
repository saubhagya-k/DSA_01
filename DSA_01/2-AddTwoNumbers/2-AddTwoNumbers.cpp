// Last updated: 05/08/2026, 17:03:27
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Dummy node to start the result list
        ListNode* curr = dummyHead;             // Pointer to build the new list
        int carry = 0;

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;  // If l1 exists, take value, else 0
            int val2 = l2 ? l2->val : 0;  // Same for l2

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            curr->next = new ListNode(sum % 10);  // Add digit to result list
            curr = curr->next;

            if (l1) l1 = l1->next;  // Move to next node if exists
            if (l2) l2 = l2->next;
        }

        return dummyHead->next;  // Return result list (skip dummy node)
    }
};
