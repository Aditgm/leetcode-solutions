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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;
        auto rec=[&](auto &&self,TreeNode *lft,TreeNode *rght,int lev){
            if(!lft or !rght) return;
            if(lev%2){
               swap(lft->val,rght->val);
            }
            self(self,lft->left,rght->right,lev+1);
            self(self,lft->right,rght->left,lev+1);
        };
        rec(rec,root->left,root->right,1);
        return root;
    }
};