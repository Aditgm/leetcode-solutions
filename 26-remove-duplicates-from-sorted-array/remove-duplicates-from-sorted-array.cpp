class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        int i=0;
        while(i<n){
            while(i+1<n and nums[i]==nums[i+1]) i++;
            nums[k++]=nums[i++];
        }
        return k;
    }
};