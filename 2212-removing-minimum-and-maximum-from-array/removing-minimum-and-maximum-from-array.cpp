class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                ans+=min(n-i,i+1);
            }
            else if(nums[i]==maxi){
                ans+=min(n-i,i+1);
            }
        }
        int ans1;
        bool miniok=0,maxiok=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mini){
                ans1=i+1;
                miniok=1;
            }
            else if(nums[i]==maxi){
                ans1=i+1;
                maxiok=1;
            }
            if(miniok and maxiok) break;
        }
        ans=min(ans,ans1);
        miniok=0,maxiok=0,ans1=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==mini){
                ans1=n-i;
                miniok=1;
            }
            else if(nums[i]==maxi){
                ans1=n-i;
                maxiok=1;
            }
            if(miniok and maxiok) break;
        }
        ans=min(ans,ans1);
        return ans;
    }
};