class Solution {
public:
    #define ll long long
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq2;
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i=0;i<n;i++){
            if(pq.size()<=2){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]>pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            if(pq2.size()<=1){
               pq2.push(nums[i]);
            }
            else{
                if(pq2.top()>nums[i]){
                   pq2.pop();
                pq2.push(nums[i]);
                }
            }
        }
        ll nums1=1,nums2=1;
        ll maxi=*max_element(nums.begin(),nums.end());
        while(!pq.empty()){
            nums1*=pq.top();pq.pop();
        }
        while(!pq2.empty()){
            nums2*=pq2.top();pq2.pop();
        }
        nums2*=maxi;
        return max(nums1,nums2);
    }
};