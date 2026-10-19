/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        TreeNode *cur=root;
        int tot=0,cursum=0;
        while(cur){
            if(!cur->left){
               cursum=cursum*10+cur->val;
               if(!cur->right) tot+=cursum;
               cur=cur->right;
            }
            else{
               TreeNode* pred=cur->left;
               int step=1;
               while(pred->right and pred->right!=cur){
                pred=pred->right;
                step++;
               }
               if(!pred->right){
                cursum=cursum*10+cur->val;
                pred->right=cur;
                cur=cur->left;
               }
               else{
                if(!pred->left){
                    tot+=cursum;
                }
                for(int i=0;i<step;i++){
                    cursum/=10;
                }
                pred->right=nullptr;
                cur=cur->right;
               }
            }
        } 
        return tot;
    }
};