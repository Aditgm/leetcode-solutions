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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        } 
        ListNode* rev=nullptr;
        ListNode* second=slow->next;
        slow->next=nullptr;
        while(second){
            ListNode* nxt=second->next;
            second->next=rev;
            rev=second;
            second=nxt;
        }
        ListNode* first=head;second=rev;
        while(second){
            ListNode* nxtfirst=first->next;
            ListNode* nxtsec=second->next;
            first->next=second;
            second->next=nxtfirst;
            first=nxtfirst;
            second=nxtsec;
        }
    }
};