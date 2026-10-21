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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        auto ismirror=[&](auto &&self,TreeNode *lft,TreeNode* rght)->bool{
            if(!lft or !rght) return lft==rght; 
            return (lft->val==rght->val) and (self(self,lft->left,rght->right)) and self(self,lft->right,rght->left);
        } ;
        return ismirror(ismirror,root->left,root->right);
    }
};