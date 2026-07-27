class Solution {
public:
    #define vi vector<int>
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vi pref(n+1,0);pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        deque<int> dq;
        int ans=n+1;
        int mini=INT_MAX;
        for(int j=0;j<=n;j++){
            while(!dq.empty() and pref[j]-pref[dq.front()]>=k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() and pref[dq.back()]>=pref[j]) dq.pop_back();
            dq.push_back(j);
        }
        return ans==n+1?-1:ans;
    }
};