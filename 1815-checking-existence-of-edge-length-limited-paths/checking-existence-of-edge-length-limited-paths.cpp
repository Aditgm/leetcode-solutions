class Solution {
public:
    #define vi vector<int>
    struct Dsu{
       vi par,rank;
       Dsu(int n){
        par.resize(n);
        rank.assign(n,0);
        iota(par.begin(),par.end(),0);
       }
       int find(int x){
        return par[x]==x?x:find(par[x]);
       }
       void unite(int a,int b){
         int roota=find(a);
         int rootb=find(b);
         if(roota!=rootb){
            if(rank[roota]<rank[rootb]){
                par[roota]=rootb;
            }
            else if(rank[roota]>rank[rootb]){
                par[rootb]=roota;
            }
            else{
                par[rootb]=roota;
                rank[roota]++;
            }
         }
       }
    };
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<vi> Q(q);
        for(int i=0;i<q;i++){
            Q[i]={queries[i][0],queries[i][1],queries[i][2],i};
        }
        auto cmp=[](const vector<int> &a,vector<int> &b){
           return a[2]<b[2];
        };
        sort(edgeList.begin(),edgeList.end(),cmp);
        sort(Q.begin(),Q.end(),cmp);
        Dsu dsu(n);
        vector<bool> ans(q);
        int idx=0,m=edgeList.size();
        for(int i=0;i<q;i++){
            int u=Q[i][0],v=Q[i][1],lim=Q[i][2];
            int id=Q[i][3];
            while(idx<m and edgeList[idx][2]<lim){
                dsu.unite(edgeList[idx][0],edgeList[idx][1]);
                idx++;
            }
            ans[id]=(dsu.find(u)==dsu.find(v));
        }
        return ans;
    }
};