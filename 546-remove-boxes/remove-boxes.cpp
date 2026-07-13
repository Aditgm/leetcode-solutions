class Solution {
public:
    int dp[101][101][101];
    int rec(const vector<int>& boxes,int i,int j,int k){
        if(i>j) return 0;
        if(dp[i][j][k]!=0) return dp[i][j][k];
        int ogi=i;
        int ogk=k;
        while(i+1<=j and boxes[i+1]==boxes[i]){
            i++;k++;
        }
        int res=(k+1)*(k+1)+rec(boxes,i+1,j,0);
        for(int m=i+1;m<=j;m++){
            if(boxes[m]==boxes[i]){
                int score=rec(boxes,i+1,m-1,0)+rec(boxes,m,j,k+1);
                res=max(res,score);
            }
        }
        return dp[ogi][j][ogk]=res;
    }
    int removeBoxes(vector<int>& boxes) {
        for(int i=0;i<100;i++){
            for(int j=0;j<100;j++){
                for(int k=0;k<100;k++){
                    dp[i][j][k]=0;
                }
            }
        }
        return rec(boxes,0,boxes.size()-1,0);
    }
};