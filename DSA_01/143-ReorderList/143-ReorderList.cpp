// Last updated: 05/08/2026, 17:00:28
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
    void reorderList(ListNode* head) {

     if (!head || !head->next) return;



        ListNode*slow = head;
        ListNode*fast = head;


        while(fast && fast->next ){
            fast = fast->next->next;
            slow = slow->next;

        }
        ListNode*second = slow->next;
        slow->next=NULL;

        ListNode*prev = NULL;
        ListNode*forw = NULL;

        while(second){
            forw = second->next;
            second->next = prev;
            prev = second;
            second = forw;

        };
      ListNode* first = head;
        ListNode* secondHead = prev;

        while (first && secondHead) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = secondHead->next;

            first->next = secondHead;
            secondHead->next = tmp1;

            first = tmp1;
            secondHead = tmp2;
        }

      

        


        

        

        


        
    }
};