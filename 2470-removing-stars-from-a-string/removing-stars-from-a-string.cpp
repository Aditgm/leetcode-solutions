class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        vector<int>v;
        vector<bool>t(n,1);
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                t[i]=0;
                t[v.back()]=0;v.pop_back();
            }
            else v.push_back(i);
        }
        string ans="";
        for(int i=0;i<n;i++)if(t[i])ans+=s[i];
        return ans;
    }
};