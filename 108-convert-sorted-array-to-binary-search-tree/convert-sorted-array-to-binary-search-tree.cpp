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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        auto rec=[&](auto &&self,int l,int r)->TreeNode*{
            if(l>r) return nullptr;
            int mid=l+(r-l)/2;
            TreeNode* node=new TreeNode(nums[mid]);
            node->left=self(self,l,mid-1);
            node->right=self(self,mid+1,r);
            return node;
        }; 
        return rec(rec,0,n-1);
    }
};