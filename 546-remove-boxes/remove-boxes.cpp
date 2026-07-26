class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        int dp[n+1][n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
               for(int k=0;k<=n;k++){
                 dp[i][j][k]=-1;
               }
            }
        }
        auto rec=[&](int i,int j,int k,auto &&self)->int{
            if(i>j) return 0;
            while(i<j and boxes[j-1]==boxes[j]){
                j--;
                k++;
            }
            int &ans=dp[i][j][k];
            if(ans!=-1) return ans;
            ans=self(i,j-1,0,self)+(k+1)*(k+1);
            for(int l=i;l<j;l++){
                if(boxes[l]==boxes[j]){
                    ans=max(ans,self(i,l,k+1,self)+self(l+1,j-1,0,self));
                }
            }
            return dp[i][j][k]=ans;
        };
        return rec(0,n-1,0,rec);
    }
};