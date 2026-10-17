class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            if(nums[mid]==target) return mid;
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target and target<nums[mid]){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            else{
                if(nums[mid]<target and nums[hi]>=target){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return -1;
    }
};