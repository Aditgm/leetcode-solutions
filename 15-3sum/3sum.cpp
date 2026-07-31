class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       for(int i=0;i<n;i++){
        int num=nums[i];
        if(num>0) continue;
        if(i>0 and nums[i]==nums[i-1]) continue;
        int l=i+1,r=n-1;
        while(l<r){
            long long sum=1ll*nums[i]+nums[l]+nums[r];
            if(sum<0) l++;
            else if(sum>0) r--;
            else{
                ans.push_back({nums[i],nums[l],nums[r]});
                int leftv=nums[l],riv=nums[r];
                while(leftv==nums[l] and l<r) l++;
                while(riv==nums[r] and l<r) r--;
            }
        }
       }
       return ans;
    }
};