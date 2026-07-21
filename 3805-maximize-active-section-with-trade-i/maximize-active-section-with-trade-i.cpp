#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 'c';
}();
class Solution {
public:
    int maxActiveSectionsAfterTrade(const string &s) {
        int tot=0,prvzer=-1,curzer=0,maxd=0;
        for(char c:s){
        if(c=='1'){
            tot++;
            if(curzer>0){
                if(prvzer!=-1){
                    if(maxd<(prvzer+curzer)){
                        maxd=prvzer+curzer;
                    }
                }
                prvzer=curzer;
                curzer=0;
            }
        }
        else curzer++;
        }
        if(curzer>0 and prvzer!=-1){
            if(maxd<(prvzer+curzer)){
                maxd=prvzer+curzer;
            }
        }
        return tot+maxd;
    }
};