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
        if(!head) return 0;
        ListNode *slow=head,*fast=head;
        ListNode*prv=nullptr;
        while(fast and fast->next){
            fast=fast->next->next;
            ListNode* nxt=slow->next;
            slow->next=prv;
            prv=slow;
            slow=nxt;
        }
        int maxi=0;
        while(slow){
            maxi=max(maxi,prv->val+slow->val);
            prv=prv->next;
            slow=slow->next;
        }
        return maxi;
    }
};