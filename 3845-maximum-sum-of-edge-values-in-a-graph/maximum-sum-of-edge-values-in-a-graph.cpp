class Solution {
public:
    #define ll long long
    long long maxScore(int n, vector<vector<int>>& edges) {
       int m=edges.size();
       int l=0,r=n-1;
       vector<int> a(n+1);
       ll ans=0;
       for(int i=1;i<=n;i++){
        if(i%2==1) a[l++]=i;
        else a[r--]=i;
       }
       if(m==n-1){
         for(int i=0;i<n;i++){
            ans+=1ll*a[i+1]*a[i];
         }
         return ans;
       }   
       else if(m==n){
          for(int i=0;i<n;i++){
            ans+=1ll*a[i+1]*a[i];
          }
          ans+=a[0]*a[n-1];
          return ans;
       }

       return -1;
    }
};