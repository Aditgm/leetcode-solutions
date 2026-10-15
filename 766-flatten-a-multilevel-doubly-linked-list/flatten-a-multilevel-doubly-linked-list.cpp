/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node *cur=head;
        while(cur){
            if(cur->child){
               Node* nextn=cur->next;
               Node* childn=cur->child;
               Node* tail=cur->child;
               while(tail->next){
                tail=tail->next;
               }
               cur->next=childn;
               childn->prev=cur;
               cur->child=nullptr;
               if(nextn){
                tail->next=nextn;
                nextn->prev=tail;
               }
            }
            cur=cur->next;
        }
        return head;
    }
};