class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i=0,j=0,k=0;
        vector<int> ans(n+m);
        while(i<n and j<m){
            if(nums1[i]<=nums2[j]) ans[k++]=nums1[i++];
            else ans[k++]=nums2[j++];
        }
        while(i<n){
            ans[k++]=nums1[i++];
        }
        while(j<m) ans[k++]=nums2[j++];
        for(int i=0;i<n+m;i++){
            nums1[i]=ans[i];
        }
    }
};