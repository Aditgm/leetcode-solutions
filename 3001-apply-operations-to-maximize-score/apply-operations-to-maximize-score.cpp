class Solution {
public:
    #define ll long long
    static constexpr ll mod=1e9+7;
    ll binpow(ll b,ll e){
        ll res=1;
        res%=mod;
        e%=mod;
        while(e>0){
            if(e&1) res=(res*b)%mod;
            b=(b*b)%mod;
            e>>=1;
        }
        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        ll score=1;
        vector<int> prime(mx+1,0);
        for(int i=2;i<=mx;i++){
             if(prime[i]==0){
                for(int j=i;j<=mx;j+=i){
                    prime[j]++;
                }
             }
        }
        vector<ll> contri(n,0);
        vector<ll> ps(n);
        for(int i=0;i<n;i++){
            ps[i]=prime[nums[i]];
        }
        vector<ll> left(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and ps[st.top()]<ps[i]) st.pop();
            left[i]=st.empty()?i+1:i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        vector<ll> right(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and ps[st.top()]<=ps[i]) st.pop();
            right[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }
        for(int i=0;i<n;i++){
            contri[i]=1ll*left[i]*right[i];
        }
        vector<pair<ll,ll>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],contri[i]});
        }
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            return a.first>b.first;
        });
        ll ans=1;
        ll ops=k;
        for(auto &[val,cnt]:arr){
            if(ops==0) break;
            ll take=min(ops,cnt);
            ans=(ans*binpow(val,take))%mod;
            ops-=take;
        }
        return ans;
    }
};