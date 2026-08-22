class Solution {
public:
    #define ll long long
    int countBinaryPalindromes(long long n) {
        if(n==0) return 1;
        int len=64-__builtin_clzll(n);
        int half=(len+1)/2;
        ll ans=01;
        for(int i=1;i<len;i++){
           ans+=(1ll<<((i-1)/2));
        }
        ll pref=n>>(len-half);
        ll small=1ll<<(half-1);
        ans+=pref-small;
        ll pal=pref;
        ll rem=(len%2)?pref>>1:pref;
        while(rem>0){
            pal=pal<<1|rem&1;
            rem>>=1;
        }
        if(pal<=n){
            ans++;
        }
        return ans;
    }
};