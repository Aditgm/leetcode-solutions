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
    bool rec(TreeNode *root,int sum,int tar){
        if(!root) return 0;
        sum+=root->val;
        if(!root->left and !root->right){
            return sum==tar;
        }
        return rec(root->left,sum,tar) ||  rec(root->right,sum,tar);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return rec(root,0,targetSum);
    }
};