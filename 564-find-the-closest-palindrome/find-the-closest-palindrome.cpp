class Solution {
public:
#define ll long long
    ll pal(ll left,bool iseven){
        ll res=left;
        if(!iseven){
            left/=10;
        }
        while(left>0){
            res=res*10+(left%10);
            left/=10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        ll len=n.length();
        ll og=stoll(n);
        if(og<=10) return to_string(og-1);
        if(og==11) return "9";
        bool iseven=(len%2==0);
        ll half=(len%2==0)?(len/2):(len/2+1);
        ll left=stoll(n.substr(0,half));
        vector<ll> cd;
        cd.push_back(pal(left,iseven));
        cd.push_back(pal(left+1,iseven));
        cd.push_back(pal(left-1,iseven));
        ll powr=1;
        for(int i=0;i<len-1;i++){
            powr*=10;
        }
        cd.push_back(powr-1);
        cd.push_back(powr*10+1);
        ll close=-1;
        ll mindif=LLONG_MAX;
        for(ll cad:cd){
            if(cad==og) continue;
            ll dif=abs(cad-og);
            if(dif<mindif){
                mindif=dif;
                close=cad;
            }
            else if(dif==mindif){
                close=min(close,cad);
            }
        }
        return to_string(close);
    }
};