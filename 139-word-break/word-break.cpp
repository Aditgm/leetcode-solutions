class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int maxi=0;
        for(const auto &w:wordDict){
            maxi=max(maxi,(int)w.size());
        }
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int len=1;len<=min(i,maxi);len++){
                if(dp[i-len] and st.count(s.substr(i-len,len))){
                    dp[i]=1;break;
                }
            }
        }
        return dp[n];
    }
};