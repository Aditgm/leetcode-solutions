class Solution {
public:
    #define ll long long
    #define vll vector<ll>
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        ll n=nums.size();ll m=cost.size();
        vll prefnums(n+1,0),prefcost(n+1,0);
        for(ll i=1;i<=n;i++){
            prefnums[i]=prefnums[i-1]+nums[i-1];
            prefcost[i]=prefcost[i-1]+cost[i-1];
        }
        vll dp(n+1,1e15);
        dp[n]=0;
        for(ll i=n-1;i>=0;i--){
            for(ll j=i;j<n;j++){
               ll numsum=prefnums[j+1];
               ll costsum=prefcost[j+1]-prefcost[i];
               ll sufcost=prefcost[n]-prefcost[i];
               ll curcost=numsum*costsum+k*sufcost;
               dp[i]=min(dp[i],curcost+dp[j+1]);
            }
        }
        return dp[0];
    }
};