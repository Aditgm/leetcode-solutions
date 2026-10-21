class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int tot=0;
        for(int i=0;i<n;i++){
           tot+=nums[i];
        }
        int left=0;
        for(int i=0;i<n;i++){
            int right=tot-left-nums[i];
            if(left==right){
                return i;
            }
            left+=nums[i];
        }
        return -1;
    }
};