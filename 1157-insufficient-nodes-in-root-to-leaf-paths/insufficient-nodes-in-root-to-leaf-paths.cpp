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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return nullptr;
        auto dfs=[&](auto &&self,TreeNode* cur,int sum)->TreeNode*{
            if(!cur) return nullptr;
            sum+=cur->val;
            if(!cur->left and !cur->right){
                return (sum>=limit)?cur:nullptr;
            }
            cur->left=self(self,cur->left,sum);
            cur->right=self(self,cur->right,sum);
            if(!cur->left and !cur->right) return nullptr;
            return cur;
        };
        return dfs(dfs,root,0);
    }
};