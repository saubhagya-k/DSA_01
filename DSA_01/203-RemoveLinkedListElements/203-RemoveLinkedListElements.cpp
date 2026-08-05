// Last updated: 05/08/2026, 16:59:14
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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode*temp = head;

        ListNode*dummyNode = new ListNode(-1);
        ListNode*must = dummyNode;

        while(temp!=NULL){
            
            if(temp->val == val){
                must->next = temp->next;
                ListNode*toDelete = temp;
                temp = temp->next;

                delete toDelete;
                
            }
            else{

            must->next = temp;
            must = temp;

            temp = temp->next;
            };

           


        }
        must->next=NULL;
        return dummyNode->next;

        
    }
};