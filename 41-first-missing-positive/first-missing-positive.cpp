class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 or nums[i]>n){
                nums[i]=n+1;
            }
        }
        for(int i=0;i<n;i++){
            int val=abs(nums[i]);
            if(val>=1 and val<=n){
                int id=val-1;
                if(nums[id]>0){
                    nums[id]=-nums[id];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};