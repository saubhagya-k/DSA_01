// Last updated: 05/08/2026, 17:03:02
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        
        

        vector<int>arr;

        

        for(int i=0;i<lists.size();i++){
            ListNode*l = lists[i];

            while(l!=NULL){
            arr.push_back(l->val);
            l=l->next;
        }

        };

        if(arr.empty()) return NULL;

        

        sort(arr.begin(),arr.end());

        ListNode*head = new ListNode(arr[0]);
        ListNode*must = head;

        for(int i=1;i<arr.size();i++){
            ListNode*temp = new ListNode(arr[i]);
            must->next = temp;
            must = temp;
            


        }



        return head;


        

        
    }

};