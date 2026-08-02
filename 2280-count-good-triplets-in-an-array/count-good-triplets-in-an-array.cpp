class Solution {
public:
#define vi vector<int>

struct fenwick{
    int n;vi tree;
    fenwick(int n){
        this->n=n;
        tree.assign(n+1,0);
    }
    void add(int i,int val){
        for(++i;i<=n;i+=i&-i){
            tree[i]+=val;
        }
    }
    int qry(int i){
        int sum=0;
        for(++i;i>0;i-=i&-i){
          sum+=tree[i];
        }
        return sum;
    }
};
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vi pos(n);
        for(int i=0;i<n;i++){
            pos[nums2[i]]=i;
        }
        fenwick bit(n);
        long long tot=0;
        for(int i=0;i<n;i++){
            int p=pos[nums1[i]];
            int left=bit.qry(p-1);
            int rght=(n-1-p)-(i-left);
            tot+=1ll*left*rght;
            bit.add(p,1);
        }
        return tot;
    }
};