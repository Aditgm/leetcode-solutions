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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        auto dfs=[&](auto &&self,TreeNode* cur,int lev)->void{
            if(!cur) return;
            if(lev==ans.size()){
                ans.push_back(cur->val);
            }
            else{
                ans[lev]=max(ans[lev],cur->val);
            }
            self(self,cur->left,lev+1);
            self(self,cur->right,lev+1);
        };
        dfs(dfs,root,0);
        return ans;
    }
};