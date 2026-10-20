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
    ListNode* removeNodes(ListNode* head) {
        auto reversell=[&](auto &&self,ListNode* head){
            ListNode* prv=nullptr,*cur=head;
            while(cur){
                ListNode* nxt=cur->next;
                cur->next=prv;
                prv=cur;
                cur=nxt;
            }
            return prv;
        };
        head=reversell(reversell,head);
        ListNode* cur=head;
        while(cur and cur->next){
            if(cur->next->val<cur->val){
                cur->next=cur->next->next;
            }
            else cur=cur->next;
        }
        ListNode* ans=reversell(reversell,head);
        return ans;
    }
};