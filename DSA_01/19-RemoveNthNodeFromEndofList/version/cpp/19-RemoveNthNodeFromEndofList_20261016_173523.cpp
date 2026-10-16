// Last updated: 16/10/2026, 17:35:23
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* removeNthFromEnd(ListNode* head, int n) {
14
15        ListNode*dummy = new ListNode(0);
16
17        dummy->next = head;
18
19        ListNode*first = dummy;
20        ListNode*second = dummy;
21
22        for(int i=0;i<=n;i++){
23            first = first->next;
24        }
25
26        while(first!=NULL){
27            first = first->next;
28            second = second->next;
29        }
30
31        ListNode*delete_node = second->next;
32
33        second->next = second->next->next;
34
35        delete delete_node;
36
37        ListNode*head2 = dummy->next;
38
39
40        return head2;
41        
42    }
43};