class Solution {
public:
    int getl(int n){
        if(n==1) return 1;
        if(n<10) return 2;
        if(n<100) return 3;
        else return 4;
    }
    int dp[101][101];
    int rec(const string &s,int i,int k){
        if(k<0) return 1e9;
        if(i==s.size() or s.size()-i<=k) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int res=rec(s,i+1,k-1);
        int same=0,dif=0;
        for(int j=i;j<s.length();j++){
            if(s[j]==s[i]) same++;
            else dif++;
            if(dif>k) break;
            res=min(res,(getl(same)+rec(s,j+1,k-dif)));
        }
        return dp[i][k]=res;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++) dp[i][j]=-1;
        }
        return rec(s,0,k);
    }
};