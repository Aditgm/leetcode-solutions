class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot=0;
        int n=machines.size();
        for(int i=0;i<n;i++){
            tot+=machines[i];
        }
        if(tot%n!=0){
            return -1;
        }
        int tar=tot/n;
        int maxi=0;
        int sum=0;
        for(int i=0;i<n;i++){
            int dif=machines[i]-tar;
            sum+=dif;
            int cur=max(abs(sum),dif);
            maxi=max(cur,maxi);
        }
        return maxi;
    }
};