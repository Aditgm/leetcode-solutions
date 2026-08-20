class Solution {
public:
    #define vi vector<int>
    struct segtree{
        int n;
        vi tree;
        segtree(int k){
            n=k;
            tree.assign(4*k,0);
        }
        void build(int node,int st,int end,vector<int> &val){
            if(st==end){
                tree[node]=val[st];
                return;
            }
            int mid=(st+end)>>1;
            build(2*node,st,mid,val);
            build(2*node+1,mid+1,end,val);
            tree[node]=max(tree[2*node],tree[2*node+1]);
        }
        int qry(int node,int st,int end,int l,int r){
            if(st>r or end<l) return 0;
            if(l<=st and end<=r) return tree[node];
            int mid=(st+end)/2;
            return max(qry(2*node,st,mid,l,r),qry(2*node+1,mid+1,end,l,r));
        }
    };
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.length();
        if(n==0) return {};
        vector<pair<int,int>> seg;
        vector<int> l(1,0);
        int i=0;
        while(i<n){
            int j=i;
            while(j<n and s[j]==s[i]) j++;
            seg.push_back({s[i],j-i});
            if(j<n) l.push_back(j);
            i=j;
        } 
        int m=seg.size();
        vector<int> pref(m+1,0);
        for(int i=0;i<m;i++){
            pref[i+1]=pref[i]+(seg[i].first=='1'?seg[i].second:0);
        }
        vector<int> cand(m,0);
        for(int i=0;i<m;i++){
            if(seg[i].first=='1'){
                int left=(i>0?seg[i-1].second:0);
                int right=(i+1<m?seg[i+1].second:0);
                cand[i]=left+right;
            }
        }
        segtree st(m);
        if(m>0){
            st.build(1,0,m-1,cand);
        }
        vector<int> ans;
        for(auto &q:queries){
            int ql=q[0],qr=q[1];
            int si=lower_bound(l.begin(),l.end(),ql+1)-l.begin()-1;
            int sj=lower_bound(l.begin(),l.end(),qr+1)-l.begin()-1;
            int curmax=0;
            if(si+2<=sj-2){
                curmax=max(curmax,st.qry(1,0,m-1,si+2,sj-2));
            }
            vector<int> arr={si,si+1,sj-1,sj};
            for(int k:arr){
                if(k>=si and k<=sj and seg[k].first=='1'){
                    int left0=0,right0=0;
                    if(k-1>=0 and seg[k-1].first=='0'){
                        int stidx=max(ql,l[k-1]);
                        int endidx=min(qr,l[k]-1);
                        if(stidx<=endidx) left0=endidx-stidx+1;
                    }
                    if(k+1<m and seg[k+1].first=='0'){
                        int stidx=max(ql,l[k+1]);
                        int endidx=min(qr,(k+2<m?l[k+2]:n)-1);
                        if(stidx<=endidx){
                            right0=endidx-stidx+1;
                        }
                    }
                    if(left0>0 and right0>0){
                        curmax=max(curmax,left0+right0);
                    }
                }
            }
            ans.push_back(pref[m]+curmax);
        }
        return ans;
    }
};