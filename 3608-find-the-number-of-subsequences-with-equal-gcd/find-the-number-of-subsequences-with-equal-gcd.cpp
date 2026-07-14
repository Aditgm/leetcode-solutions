class Solution {
public:
    const int mod=1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<int>> dp(201,vector<int>(201,0));
        for(int x:nums){
            vector<vector<int>> ndp=dp;
            for(int g1=0;g1<=200;g1++){
               for(int g2=0;g2<=200;g2++){
                if(dp[g1][g2]==0) continue;
                int ng1=(g1==0)?x:__gcd(g1,x);
                ndp[ng1][g2]=(ndp[ng1][g2]+dp[g1][g2])%mod;
               }
            }
            for(int g1=0;g1<=200;g1++){
                for(int g2=0;g2<=200;g2++){
                    if(dp[g1][g2]==0) continue;
                    int ng2=(g2==0)?x:__gcd(g2,x);
                    ndp[g1][ng2]=(ndp[g1][ng2]+dp[g1][g2])%mod;
                }
            }
            ndp[x][0]=(ndp[x][0]+1)%mod;
            ndp[0][x]=(ndp[0][x]+1)%mod;
            dp=ndp;
        }
        long long ans=0;
        for(int i=1;i<=200;i++){
            ans=(ans+dp[i][i])%mod;
        }
        return (int)ans;
    }
};