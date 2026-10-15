class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        int l=0;
        while(l+1<n and nums[l]<=nums[l+1]) l++;
        if(l==n-1) return 0; 
        int r=n-1;
        while(r>0 and nums[r]>=nums[r-1]) r--;
        int mini=*min_element(nums.begin()+l,nums.begin()+r+1);
        int maxi=*max_element(nums.begin()+l,nums.begin()+r+1);
        while(l>0 and nums[l-1]>mini) l--;
        while(r+1<n and nums[r+1]<maxi) r++;
        return r-l+1;
    }
};