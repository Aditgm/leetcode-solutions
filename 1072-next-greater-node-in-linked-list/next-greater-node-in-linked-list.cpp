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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> st;
        int idx=0;
        for(ListNode* cur=head;cur!=nullptr;cur=cur->next){
            ans.push_back(0);
            while(!st.empty() and cur->val>st.top().second){
            ans[st.top().first]=cur->val;
            st.pop();
            }
        st.push({idx++,cur->val});
    }
    return ans;
}
};