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
    int findBottomLeftValue(TreeNode* root) {
        int maxi=-1;
        int ans=0;
        auto rec=[&](auto&& self,TreeNode* node,int dep)->void{
            if(!node) return;
            if(dep>maxi){
                maxi=dep;
                ans=node->val;
            }
            self(self,node->left,dep+1);
            self(self,node->right,dep+1);
        };
        rec(rec,root,0);
        return ans;
    }
};