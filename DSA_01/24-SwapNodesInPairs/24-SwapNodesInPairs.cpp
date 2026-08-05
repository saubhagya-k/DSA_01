// Last updated: 05/08/2026, 17:03:01
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
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL ){
            return head;
        }


        ListNode* demo = new ListNode(0); 

        demo->next = head; 

       
       
       

        ListNode* prev = demo;



        while(prev->next!= NULL && prev->next->next!=NULL){

             ListNode* temp = prev->next;

             ListNode* curr = prev->next->next;

            prev->next = curr;
            temp->next = curr->next ;
            curr->next = temp;

            prev = temp;



        }


        return demo->next;



        
    }
};