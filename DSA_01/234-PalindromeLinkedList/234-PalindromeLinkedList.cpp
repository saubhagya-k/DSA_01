// Last updated: 05/08/2026, 16:58:42
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
    bool isPalindrome(ListNode* head) {

        stack<int>st={};

        ListNode*temp=head;

        while(temp!= nullptr){
        st.push(temp->val);
        temp = temp->next;
        
        }

        temp=head;

        while(temp!=nullptr){
            if(temp->val == st.top()){

            }
            else{
                return false;
                break;
            }
            st.pop();

            temp = temp->next;


    

        }
        return true;




       

       
        
    }
};