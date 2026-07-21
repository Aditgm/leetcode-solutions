class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int tot=0,prvzer=-1,curzer=0,maxd=0;
        for(char c:s){
        if(c=='1'){
            tot++;
            if(curzer>0){
                if(prvzer!=-1){
                    maxd=max(maxd,prvzer+curzer);
                }
                prvzer=curzer;
                curzer=0;
            }
        }
        else curzer++;
        }
        if(curzer>0 and prvzer!=-1){
            maxd=max(maxd,prvzer+curzer);
        }
        return tot+maxd;
    }
};