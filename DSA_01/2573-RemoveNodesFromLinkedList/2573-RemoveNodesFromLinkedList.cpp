// Last updated: 05/08/2026, 16:52:37
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
    ListNode* removeNodes(ListNode* head) {
        ListNode*temp = head;
        ListNode*must = NULL;
        ListNode*oh = NULL;
        

        while(temp){
            must = temp->next;
            temp->next = oh;
            oh=temp;
            temp=must;

        }
       

        ListNode*p = oh;
        ListNode*q=oh->next;
        ListNode*r = NULL;
        int max_VAL = p->val;

        while(q!=NULL){
            r=q->next;

            if(q->val < max_VAL){
               
                p->next = r;
               q=r;

            }
            else{
                max_VAL = q->val;
                p=q;
                q=r;
            }

        }
        temp = oh;
        must = NULL;
        ListNode* newHead = NULL;

        while (temp) {
            must = temp->next;
            temp->next = newHead;
            newHead = temp;
            temp = must;
        }

        return newHead;

        
    }
};