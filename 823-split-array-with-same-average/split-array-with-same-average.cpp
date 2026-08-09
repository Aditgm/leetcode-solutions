class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int m=n/2;
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        bool ok=0;
        for(int i=1;i<=n/2;i++){
            if((tot*i)%n==0){
               ok=1;break;
            }
        }
        if(!ok) return 0;
        vector<bitset<300005>> dp(m+1);
        dp[0][0]=1;
        for(auto it:nums)
          for(int i=m;i>=1;i--){
            dp[i]=dp[i]|dp[i-1]<<it;
        }
        for(int i=1;i<=m;i++){
            if((tot*i)%n==0){
                int tar=(tot*i)/n;
                if(dp[i][tar]){
                    return 1;
                }
            }
        }
        return 0;
    }
};