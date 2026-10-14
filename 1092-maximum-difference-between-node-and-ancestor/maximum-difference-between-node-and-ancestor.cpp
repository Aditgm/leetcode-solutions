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
    int maxAncestorDiff(TreeNode* root) {
        int bst=INT_MIN;
        if(!root) return 0;
        auto dfs=[&](auto &&self,TreeNode *node,int mini,int maxi){
            if(!node){
                return maxi-mini;
            }
            mini=min(mini,node->val);
            maxi=max(maxi,node->val);
            return max(self(self,node->left,mini,maxi),self(self,node->right,mini,maxi));
        };
        return dfs(dfs,root,INT_MAX,INT_MIN);
        
    }
};