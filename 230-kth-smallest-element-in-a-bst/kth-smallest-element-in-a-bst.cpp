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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur=root;
        int ans=-1;
        while(cur){
            if(!cur->left){
                if(--k==0) ans=cur->val;
                cur=cur->right;
            }
            else{
                TreeNode* pred=cur->left;
                while(pred->right and pred->right!=cur){
                   pred=pred->right;
                }
                if(!pred->right){
                    pred->right=cur;
                    cur=cur->left;
                }
                else{
                    pred->right=nullptr;
                    if(--k==0) ans=cur->val;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};