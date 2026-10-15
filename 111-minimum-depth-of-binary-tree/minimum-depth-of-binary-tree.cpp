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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        auto rec=[&](auto &&self,TreeNode* node,int lev){
            if(!node) return;
            if(!node->left and !node->right){
                ans=min(ans,lev);
                return;
            }
            self(self,node->left,lev+1);
            self(self,node->right,lev+1);
        };
        rec(rec,root,1);
        return ans;
    }
};