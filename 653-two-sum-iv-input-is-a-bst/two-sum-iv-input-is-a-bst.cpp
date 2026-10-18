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
    bool findTarget(TreeNode* root, int k) {
        TreeNode* cur=root;
        bool found=0;
        auto searchbst=[&](auto &&self,TreeNode* cur,int target)->bool{
            if(target>=cur->val) return 0;
            TreeNode* runner=root;
            while(runner){
                if(runner->val==target and runner!=cur){
                    return true;
                }
                else if(target<runner->val){
                    runner=runner->left;
                }
                else runner=runner->right;
            }
            return 0;
        };
        while(cur){
            if(!cur->left){
                if(!found and searchbst(searchbst,cur,k-cur->val)) found=1;
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
                    if(!found and searchbst(searchbst,cur,k-cur->val)) found=1;
                    cur=cur->right;
                }
            }
        }
        return found;
    }
};