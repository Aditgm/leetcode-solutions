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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        auto dfs=[&](auto &&self,TreeNode* cur,int cursum)->int{
            if(!cur) return 0;
            cursum=cursum*10+cur->val;
            if(!cur->left and !cur->right) return cursum;
            return self(self,cur->left,cursum)+self(self,cur->right,cursum);
        };
        return dfs(dfs,root,0);
    }
};