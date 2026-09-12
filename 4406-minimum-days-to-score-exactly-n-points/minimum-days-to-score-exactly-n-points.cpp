class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1,1e9);
        dp[0]=-1;
        for(int i=0;i<=n;i++){
            if(dp[i]==1e9) continue;
            for(int k=1;;k++){
                int p=(k*(k+1))/2;
                if(i+p>n) break;
                dp[i+p]=min(dp[i+p],dp[i]+k+1);
            }
        }
        return dp[n];
    }
};