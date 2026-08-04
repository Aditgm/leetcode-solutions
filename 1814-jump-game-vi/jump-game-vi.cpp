class Solution {
public:
    #define vi vector<int>
    #define pb push_back
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vi dp(n+1,0);
        deque<int> dq;
        dp[0]=nums[0];
        dq.pb(0);
        for(int i=1;i<n;i++){
            if(!dq.empty() and dq.front()<i-k){
                dq.pop_front();
            }
            dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty() and dp[dq.back()]<=dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[n-1];
    }
};