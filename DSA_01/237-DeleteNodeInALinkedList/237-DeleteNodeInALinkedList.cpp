// Last updated: 05/08/2026, 16:58:33
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;        // Copy next node's value
        ListNode* temp = node->next;
        node->next = node->next->next;      // Skip the next node
        delete temp;  


        
    }
};