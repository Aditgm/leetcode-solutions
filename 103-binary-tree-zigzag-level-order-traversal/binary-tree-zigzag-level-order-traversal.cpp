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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltor=1;
        while(!q.empty()){
           int sz=q.size();
           vector<int> lev(sz);
           for(int i=0;i<sz;i++){
              TreeNode* cur=q.front();
              q.pop();
              int id=ltor?i:(sz-i-1);
              lev[id]=cur->val;
              if(cur->left) q.push(cur->left);
              if(cur->right) q.push(cur->right);
           }
           ans.push_back(lev);
           ltor^=1;
        }
        return ans;
    }
};