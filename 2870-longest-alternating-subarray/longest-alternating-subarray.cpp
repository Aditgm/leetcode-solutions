class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
       int n=nums.size();
       int bst=-1,cur=-1;
       for(int i=1;i<n;i++){
        int dif=nums[i]-nums[i-1];
        if(cur>1 and dif==(cur%2==0?-1:1)){
            cur++;
        }
        else if(dif==1) cur=2;
        else cur=1;
        if(cur>=2){
            bst=max(bst,cur);
        }
       }
       return bst;
    }
};