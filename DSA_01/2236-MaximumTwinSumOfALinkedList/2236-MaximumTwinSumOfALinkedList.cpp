// Last updated: 05/08/2026, 16:52:48
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
    int pairSum(ListNode* head) {

        ListNode*slow = head;
        ListNode*fast = head;

        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;

        }

        ListNode*lundry = NULL;

        while(slow!=NULL){
            ListNode*sir = slow->next;
            slow->next= lundry;
            lundry = slow;
            slow=sir;

        }
        int ans = 0;

        while(lundry!=NULL){
            ans = max(ans,head->val+lundry->val);
            head = head->next;
            lundry = lundry->next;
        }


        return ans;
        
    }
};