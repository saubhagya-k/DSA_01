// Last updated: 05/08/2026, 17:01:59
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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL){ 
            return head;
        }

        ListNode*firstDummy = new ListNode(0);
        ListNode*secondDummy = new ListNode(0);

        ListNode*first = firstDummy;
        ListNode*second = secondDummy;

        ListNode*main = head;

        while(main){
            if(main->val<x){
                first->next = main;
                first = first->next;
            }

            else{
                second->next = main;
                second = second->next;
            }

            main = main->next;
        }

        second->next = NULL;

        first->next = secondDummy->next;

        return firstDummy->next;




        
    }
};