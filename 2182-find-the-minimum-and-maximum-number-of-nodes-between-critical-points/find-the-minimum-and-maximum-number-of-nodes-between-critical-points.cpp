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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head or !head->next or !head->next->next) return {-1,-1};
        int first=-1,prvc=-1,mindist=INT_MAX;
        ListNode* prv=head;
        ListNode *curr=head->next;
        int id=1;
        while(curr->next!=NULL){
            if((curr->val>prv->val and curr->val>curr->next->val) or (curr->val<prv->val and curr->val<curr->next->val)){
                if(first==-1){
                    first=id;
                }
                else{
                    mindist=min(mindist,id-prvc);
                }
                prvc=id;
            }
                prv=curr;
                curr=curr->next;
                id++;
            }
            if(mindist==INT_MAX){
                return {-1,-1};
            }
            int maxdist=prvc-first;
            return {mindist,maxdist};
    }
};