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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root) return 0;
        auto match=[&](auto &&self,TreeNode* node,ListNode* cur)->bool{
            if(!cur) return 1;
            if(!node) return 0;
            if(node->val!=cur->val) return 0;
            return self(self,node->left,cur->next) or self(self,node->right,cur->next);
        };
        return match(match,root,head) or isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};