// Last updated: 05/08/2026, 17:00:36
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
    bool hasCycle(ListNode *head) {
      
      ListNode*slow = head;
      ListNode*fast = head;

      if(  head == NULL || head->next == NULL) return false;

      while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast )  return true;

        
      };
      return false;




        
    };

};