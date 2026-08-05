// Last updated: 05/08/2026, 17:00:39
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp = head;
        if (!head) return NULL;
        while(temp!=NULL){
            Node*copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        };

        temp = head;

        while(temp!=NULL){


            if(temp->random){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        };


        temp = head;

        Node*dNode = new Node (-1);
        Node*res = dNode;
        while(temp!=NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dNode->next;






        
    }
};