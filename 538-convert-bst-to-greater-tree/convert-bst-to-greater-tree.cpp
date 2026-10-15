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
    TreeNode* convertBST(TreeNode* root) {
        long long sum=0;
        auto rec=[&](auto &&self,TreeNode* node)->void{
            if(!node) return;
            self(self,node->right);
            sum+=node->val;
            node->val=sum;
            self(self,node->left);
        };
        rec(rec,root);
        return root;
    }
};