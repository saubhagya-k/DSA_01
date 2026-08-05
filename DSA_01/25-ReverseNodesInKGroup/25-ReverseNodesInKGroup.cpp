// Last updated: 05/08/2026, 17:02:58
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL || k==1){
            return head;
        }
        ListNode*temp = head;
        int n = 0;

        while(temp!=NULL){
            n++;
            temp = temp->next;
        }

        ListNode*dummy = new ListNode(0);
        dummy->next = head;

        ListNode*prevGroupTail = dummy;
        ListNode*curr = head;

        int groups = n/k;

    while(groups>0){
        ListNode*groupHead = curr;
        ListNode*prev = NULL;
        ListNode*nextNode = NULL;

        for(int i=0;i<k;i++){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        prevGroupTail->next = prev;
            groupHead->next = curr;

            // Move the tail pointer to preparation for next group
            prevGroupTail = groupHead;
            groups--;
            
        }

        ListNode*newHead = dummy->next;
        delete dummy;


        return newHead;



        
    }
};