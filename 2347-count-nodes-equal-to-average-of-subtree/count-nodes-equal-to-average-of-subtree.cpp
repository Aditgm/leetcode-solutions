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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        auto dfs=[&](auto &&self,TreeNode* node)->pair<int,int>{
            if(!node) return {0,0};
            auto [leftsum,leftcnt]=self(self,node->left);
            auto [rightsum,rightcnt]=self(self,node->right);
            int totsum=leftsum+rightsum+node->val;
            int totcnt=leftcnt+rightcnt+1;
            if((totsum/totcnt)==node->val) ans++;
            return {totsum,totcnt};
        };
        dfs(dfs,root);
        return ans;
    }
};