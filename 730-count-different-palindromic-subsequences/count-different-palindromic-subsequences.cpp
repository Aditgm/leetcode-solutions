class Solution {
public:
    const long long mod=1e9+7;
    #define ll long long
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
              int j=i+len-1;
              if(s[i]==s[j]){
                int low=i+1;
                int hi=j-1;
                while(low<=hi and s[low]!=s[i]) low++;
                while(low<=hi and s[hi]!=s[j]) hi--;
                if(low>hi){
                    dp[i][j]=dp[i+1][j-1]*2+2;
                }
                else if(low==hi){
                    dp[i][j]=dp[i+1][j-1]*2+1;
                }
                else{
                    dp[i][j]=dp[i+1][j-1]*2-dp[low+1][hi-1];
                }
              }
              else{
                dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
              }
              dp[i][j]=(dp[i][j]%mod+mod)%mod;
            }
        }
        return dp[0][n-1];
    }
};