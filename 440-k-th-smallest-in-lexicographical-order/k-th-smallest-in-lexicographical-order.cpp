class Solution {
public:
     #define ll long long
     ll cnt(ll n,ll cur,ll nxt){
        ll num=0;
        while(cur<=n){
            num+=min(n+1,nxt)-cur;
            cur*=10;
            nxt*=10;
        }
        return num;
     }
    int findKthNumber(int n, int k) {
        ll cur=1;
        k-=1;
        while(k>0){
            ll step=cnt(n,cur,cur+1);
            if(step<=k){
                cur+=1;
                k-=step;
            }
            else {
                cur*=10;
                k-=1;
            }
        }
        return cur;
    }
};