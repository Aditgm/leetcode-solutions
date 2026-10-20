class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo=1,hi=*max_element(nums.begin(),nums.end());
        long long ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long op=0;
            for(int x:nums){
                op+=(x-1)/mid;
                if(op>maxOperations) break;
            }
            if(op<=maxOperations){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};