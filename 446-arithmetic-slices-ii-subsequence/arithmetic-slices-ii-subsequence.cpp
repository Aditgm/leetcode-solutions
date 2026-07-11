class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        unordered_map<long long, vector<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }

        int total_ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long target = 2LL * nums[j] - nums[i];

                if (pos.count(target)) {
                    for (int k : pos[target]) {
                        if (k >= j) break;
                        dp[i][j] += dp[j][k] + 1;
                    }
                }

                total_ans += dp[i][j];
            }
        }

        return total_ans;
    }
};