class BookMyShow {
public:
    #define ll long long
        struct node{
            ll sum,maxi;
        };
        int n,m;
        vector<node> tree;
        int minr;
        void build(int node,int st,int end){
            if(st==end){
                tree[node].sum=m;
                tree[node].maxi=m;
                return;
            }
            int mid=st+(end-st)/2;
            build(2*node,st,mid);
            build(2*node+1,mid+1,end);
            tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
            tree[node].maxi=max(tree[2*node].maxi,tree[2*node+1].maxi);
        }
        void update(int node,int l,int r,int idx,int val){
            if(l==r){
                tree[node].sum-=val;
                tree[node].maxi-=val;
                return;
            }
            int mid=l+(r-l)/2;
            if(idx<=mid){
                update(2*node,l,mid,idx,val);
            }
            else{
                update(2*node+1,mid+1,r,idx,val);
            }
            tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
            tree[node]
.maxi=max(tree[2*node].maxi,tree[2*node+1].maxi);        }
        ll qrysum(int node,int l,int r,int st,int end){
            if(r<st or l>end) return 0;
            if(l>=st and r<=end) return tree[node].sum;
            int mid=l+(r-l)/2;
            return qrysum(2*node,l,mid,st,end)+qrysum(2*node+1,mid+1,r,st,end);
        }
        ll qrymaxi(int node,int l,int r,int maxr,int val){
            if(tree[node].maxi<val or l>maxr) return -1;
            if(l==r) return l;
            int mid=l+(r-l)/2;
            int res=qrymaxi(2*node,l,mid,maxr,val);
            if(res==-1){
                res=qrymaxi(2*node+1,mid+1,r,maxr,val);
            }
            return res;
        }
    BookMyShow(int n, int m) {
        this->n=n;
        this->m=m;
        tree.resize(4*n);
        build(1,0,n-1);
        minr=0;
    }
    
    vector<int> gather(int k, int maxRow) {
        if(k>m) return {};
        int r=qrymaxi(1,0,n-1,maxRow,k);
        if(r==-1) return {};
        ll aval=qrysum(1,0,n-1,r,r);
        ll start=m-aval;
        update(1,0,n-1,r,k);
        return {r,(int)start};
    }
    
    bool scatter(int k, int maxRow) {
        ll tot=qrysum(1,0,n-1,minr,maxRow);
        if(tot<k) return 0;
        for(int i=minr;i<=maxRow and k>0;i++){
            ll row=qrysum(1,0,n-1,i,i);
            if(row>0){
                ll take=min((ll)k,row);
                update(1,0,n-1,i,take);
                k-=take;
            }
            if(qrysum(1,0,n-1,i,i)==0) minr=i+1;
        }
        return 1;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */