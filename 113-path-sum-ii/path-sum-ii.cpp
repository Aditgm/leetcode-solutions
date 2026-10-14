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
    void rec(TreeNode* root,int sum,int tar,vector<int> cur,vector<vector<int>> &ans){
        if(!root) return;
        cur.push_back(root->val);
        sum+=root->val;
        if(!root->left and !root->right){
            if(sum==tar){
                ans.push_back(cur);
            }
        }
        rec(root->left,sum,tar,cur,ans);
        rec(root->right,sum,tar,cur,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> ans;
      vector<int> cur;
      rec(root,0,targetSum,cur,ans);
      return ans;  
    }
};