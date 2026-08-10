class Solution {
public:
#define ll long long
#define vi vector<int>
struct Bit{
    int n;
    vector<ll> tree;
    Bit(int n):n(n),tree(n+1,0){}
    void add(int i,ll val){
        for(++i;i<=n;i+=i&-i) tree[i]+=val;
    }
    ll qry(int i){
        ll sum=0;
        for(++i;i>0;i-=i&-i){
            sum+=tree[i];
        }
        return sum;
    }
    ll qry(int l,int r){
        if(l>r) return 0;
        return qry(r)-qry(l-1);
    }
};
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        Bit bit(n);
        set<int> peaks;
        auto getprv=[&](int idx)->int{
            auto it=peaks.lower_bound(idx);
            if(it==peaks.begin()) return 0;
            --it;
            return *it;
        };
        auto ispeak=[&](int i)->bool{
            if(i<=0 or i>=n-1) return 0;
            return nums[i]>nums[i+1] and nums[i]>nums[i-1];
        };
        auto insert=[&](int x){
            ll newprv=getprv(x);
            auto it=peaks.upper_bound(x);
            if(it!=peaks.end()){
                int nxt=*it;
                ll oldval=1ll*nxt*(nxt-newprv);
                bit.add(nxt,-oldval);
                ll newval=1ll*nxt*(nxt-x);
                bit.add(nxt,newval);
            }
            peaks.insert(x);
            ll vali=1ll*x*(newprv-x)*-1;
            bit.add(x,vali);
        };
        auto rempeak=[&](int x){
            ll prv=getprv(x);
            ll vali=1ll*x*(x-prv);
            bit.add(x,-vali);
            auto it=peaks.upper_bound(x);
            if(it!=peaks.end()){
                int nxt=*it;
                ll oldval=1ll*nxt*(nxt-x);
                bit.add(nxt,-oldval);
                ll newval=1ll*nxt*(nxt-prv);
                bit.add(nxt,newval);
            }
            peaks.erase(x);
        };
        for(int i=1;i<n-1;i++){
            if(ispeak(i)){
                insert(i);
            }
        }
        vector<ll> ans;
        for(auto &q:queries){
            if(q[0]==1){
                int l=q[1],r=q[2];
                auto ita=peaks.lower_bound(l+1);
                if(ita==peaks.end() or *ita>=r){
                    ans.push_back(0);
                    continue;
                }
                int a=*ita;
                auto itb=peaks.lower_bound(r);
                --itb;
                int b=*itb;
                int prva=getprv(a);
                ll w=bit.qry(a,b);
                ll res=1ll*r*(b-l)-w+1ll*a*(l-prva);
                ans.push_back(res);
            }
            else{
                int idx=q[1],val=q[2];
                vi cand;
                for(int i=idx-1;i<=idx+1;i++){
                    if(i>0 and i<n-1) cand.push_back(i);
                }
                for(int c:cand){
                    if(ispeak(c)) rempeak(c);
                }
                nums[idx]=val;
                for(int c:cand){
                    if(ispeak(c)){
                        insert(c);
                    }
                }
            }
        }
        return ans;
    }
};