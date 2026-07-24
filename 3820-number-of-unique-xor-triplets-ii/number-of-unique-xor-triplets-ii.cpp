class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        bool seen[2048]={0};
        vector<int> num;
        for(int x:nums){
            if(!seen[x]){
                seen[x]=1;
                num.push_back(x);
            }
        }
        bool round[2048]={0};
        for(int x:num){
            for(int y:num){
                round[x^y]=1;
            }
        }
        bool round2[2048]={0};
        int cnt=0;
        for(int i=0;i<2048;i++){
            if(round[i]){
                for(int x:num){
                    int val=i^x;
                    if(!round2[val]){
                        round2[val]=1;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};