class Solution {
public:
    #define ll long long
    const ll mod=1e9+7;
    int numberOfWays(string s) {
        int n=s.length();
        vector<int> idx;
        for(int i=0;i<n;i++){
            if(s[i]=='S') idx.push_back(i); 
        }
        if(idx.empty() or idx.size()&1) return 0;
        int ans=1;
        for(int i=1;i<idx.size()-2;i+=2){
          ll choice=idx[i+1]-idx[i];
          if(choice>0) ans=(ans*choice)%mod;
        }
        return ans;
    }
};