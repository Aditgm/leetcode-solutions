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
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        auto dfs=[&](auto &&self,TreeNode* node,int mask)->int{
            if(!node) return 0;
            mask^=(1<<node->val);
            if(!node->left and !node->right){
                return (mask&(mask-1))==0?1:0;
            }
            return self(self,node->left,mask)+self(self,node->right,mask);
        };
        return dfs(dfs,root,0);
    }
};