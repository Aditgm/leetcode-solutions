class Solution {
public:
    void dfs(TreeNode* root, int remainingSum, vector<int>& cur, vector<vector<int>>& ans) {
        if (!root) return;

        cur.push_back(root->val);
        remainingSum -= root->val;

        // Leaf node check
        if (!root->left && !root->right) {
            if (remainingSum == 0) {
                ans.push_back(cur); // Only copy when a valid path is found
            }
        } else {
            dfs(root->left, remainingSum, cur, ans);
            dfs(root->right, remainingSum, cur, ans);
        }

        // Backtrack
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(root, targetSum, cur, ans);
        return ans;
    }
};