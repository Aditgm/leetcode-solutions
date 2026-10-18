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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        auto inorder=[&](auto &&self,TreeNode* cur,vector<int> &v)->void{
            if(!cur) return;
            self(self,cur->left,v);
            v.push_back(cur->val);
            self(self,cur->right,v);
        };
        inorder(inorder,root1,v1);
        inorder(inorder,root2,v2);
        vector<int> ans;
        ans.reserve(v1.size()+v2.size());
        int i=0,j=0;
        while(i<v1.size() and j<v2.size()){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i++]);
            }
            else ans.push_back(v2[j++]);
        }
        while(i<v1.size()) ans.push_back(v1[i++]);
        while(j<v2.size()) ans.push_back(v2[j++]);
        return ans;
    }
};