class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-2;
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            if(mid%2==1) mid=mid^1;
            if(nums[mid]==nums[mid+1]){
               lo=mid+2;
            }
            else hi=mid-1;
        }
        return nums[lo];
    }
};