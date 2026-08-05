// Last updated: 05/08/2026, 17:02:25
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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode*tail = head;
        int count=1;


        if(head == NULL )return NULL;
        
        while(tail->next!=NULL){
            count++;
            tail = tail->next;

        };
        

        if(k%count == 0) return head;

        k = k%count;

        tail->next = head;

         ListNode*temp = head;

        for(int i=1;i<count-k;i++){
           
            temp = temp->next;

        }

        head = temp->next;
        
        temp->next = NULL;
       


        return head;

        
    };
};