class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if(n1==0) return 0;
        int len1=s1.length(),len2=s2.length();
        vector<int> repeatcnt(n1+1,0);
        vector<int> nextid(n1+1,0);
        vector<int> seen(len2,-1);
        int j=0,cnt=0;
        for(int k=1;k<=n1;k++){
            for(int i=0;i<len1;i++){
               if(s1[i]==s2[j]){
                 j++;
                 if(j==len2){
                    j=0;cnt++;
                 }
               }
            }
            repeatcnt[k]=cnt;
            nextid[k]=j;
            if(seen[j]!=-1){
                int st=seen[j];
                int cyclelen=k-st;
                int cyclem=cnt-repeatcnt[st];
                int rem=n1-st;
                int fullcy=rem/cyclelen;
                int ex=rem%cyclelen;
                int tot=repeatcnt[st]+(fullcy*cyclem)+(repeatcnt[st+ex]-repeatcnt[st]);
                return tot/n2;
            }
            seen[j]=k;
        }
        return repeatcnt[n1]/n2;
    }
};