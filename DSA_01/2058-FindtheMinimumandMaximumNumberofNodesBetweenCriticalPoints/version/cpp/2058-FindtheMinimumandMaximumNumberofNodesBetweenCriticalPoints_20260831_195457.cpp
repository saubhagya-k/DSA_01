// Last updated: 31/08/2026, 19:54:57
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
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14
15       
16
17        ListNode*first = head->next;
18        ListNode*second  = head;
19
20        int i = 1;
21
22        int prevC = 0;
23
24        int firstC = 0;
25
26        int minDist = INT_MAX;
27
28        while(first->next !=NULL){
29            if(second->val>first->val && first->val<first->next->val  ||  second->val<first->val && first->val>first->next->val){
30
31                if(prevC == 0){
32                    prevC = i;
33                    firstC = i;
34                }
35                else{
36                    minDist = min(minDist,i - prevC);
37                    prevC = i;
38                }
39
40            }
41            i++;
42            second = first;
43            first = first->next;
44        }
45        if(minDist == INT_MAX){
46            return {-1,-1};
47        }
48
49        return  {minDist,prevC - firstC};
50        
51    }
52};