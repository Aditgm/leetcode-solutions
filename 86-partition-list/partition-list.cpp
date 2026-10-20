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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessd(0),greatd(0);
        ListNode* lesstail=&lessd;
        ListNode* greattail=&greatd;
        while(head){
            if(head->val<x){
                lesstail->next=head;
                lesstail=lesstail->next;
            }
            else{
                greattail->next=head;
                greattail=greattail->next;
            }
            head=head->next;
        }
        greattail->next=nullptr;
        lesstail->next=greatd.next;
        return lessd.next;
    }
};