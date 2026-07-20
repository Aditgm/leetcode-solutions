class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                ans=nums[i];
            }
            cnt+=(ans==nums[i])?1:-1;
        }
        return ans;
    }
};