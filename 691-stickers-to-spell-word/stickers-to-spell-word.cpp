class Solution {
public:
    unordered_map<string,int> dp;
    int rec(vector<vector<int>> &cnt,string target){
        if(target.empty()) return 0;
        if(dp.count(target)) return dp[target];
        vector<int> targetcnt(26,0);
        for(char c:target){
            targetcnt[c-'a']++;
        }
        int res=1e9;
        int first=-1;
        for(int i=0;i<26;i++){
            if(targetcnt[i]>0){
                first=i;break;
            }
        }
        for(const auto &st:cnt){
            if(st[first]>0){
                string next="";
                for(int i=0;i<26;i++){
                    int rem=targetcnt[i]-st[i];
                    if(rem>0){
                        next+=string(rem,i+'a');
                    }
                }
                int sub=rec(cnt,next);
                if(sub!=1e9){
                    res=min(res,1+sub);
                }
            }
        }
        return dp[target]=res;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n=stickers.size();
        vector<vector<int>> cnt(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(char c:stickers[i]){
                cnt[i][c-'a']++;
            }
        }
        int res=rec(cnt,target);
        return (res==1e9)?-1:res;
    }
};