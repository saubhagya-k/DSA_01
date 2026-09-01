// Last updated: 01/09/2026, 16:19:18
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

       

        ListNode*first = head->next;
        ListNode*second  = head;

        int i = 1;

        int prevC = 0;

        int firstC = 0;

        int minDist = INT_MAX;

        while(first->next !=NULL){
            if(second->val>first->val && first->val<first->next->val  ||  second->val<first->val && first->val>first->next->val){

                if(prevC == 0){
                    prevC = i;
                    firstC = i;
                }
                else{
                    minDist = min(minDist,i - prevC);
                    prevC = i;
                }

            }
            i++;
            second = first;
            first = first->next;
        }
        if(minDist == INT_MAX){
            return {-1,-1};
        }

        return  {minDist,prevC - firstC};
        
    }
};