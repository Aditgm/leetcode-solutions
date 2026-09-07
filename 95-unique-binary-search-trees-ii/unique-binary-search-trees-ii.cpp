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
    vector<vector<vector<TreeNode*>>> memo;
    vector<TreeNode*> build(int l,int r){
        if(r<l) return {nullptr};
        if(!memo[l][r].empty()) return memo[l][r];
        vector<TreeNode*> ans;
        for(int root=l;root<=r;root++){
            for(TreeNode* left:build(l,root-1)){
                for(TreeNode* right:build(root+1,r)){
                    ans.push_back(new TreeNode(root,left,right));
                }
            }
        }
        return memo[l][r]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        memo.assign(n+2,vector<vector<TreeNode*>>(n+2));
        return build(1,n);
    }
};