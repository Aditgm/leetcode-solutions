class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int> cnt(26,0);
        for(char c:s){
            cnt[c-'a']++;
        }
        char middle='0';
        string ans="";
        for(int i=0;i<26;i++){
           int num=cnt[i]/2;
           ans.append(num,char(i+'a'));
           if(cnt[i]%2){
            middle=char(i+'a');
           }
        }
        string ret=ans;
        if(middle!='0'){
            ret+=middle;
        }
        reverse(ans.begin(),ans.end());
        ret+=ans;
        return ret;
    }
};