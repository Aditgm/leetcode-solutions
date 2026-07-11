class Solution {
public:
    #define ll long long
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        ll tot=0;
        vector<unordered_map<ll,int>> dp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                ll dif=(ll)nums[j]-nums[i];
                int cnt=dp[j].count(dif)?dp[j][dif]:0;
                tot+=cnt;
                dp[i][dif]+=cnt+1;
            }
        }
        return (int)tot;
    }
};