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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MIN;
        auto rec=[&](auto &&self,TreeNode *node){
            if(!node) return 0;
            int cur=node->val;
            int lftm=max(0,self(self,node->left));
            int rightm=max(0,self(self,node->right));
            ans=max(ans,node->val+lftm+rightm);
            return node->val+max(lftm,rightm);
        };
         rec(rec,root);
        return ans;
    }
};