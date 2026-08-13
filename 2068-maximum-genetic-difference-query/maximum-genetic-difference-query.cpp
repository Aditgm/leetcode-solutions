class Solution {
public:
    struct trienode{
       trienode *child[2];
       int cnt;
       trienode(){
        child[0]=nullptr;child[1]=nullptr;
        cnt=0;
       }
    };
    trienode* root=new trienode();
    void insert(int val,int flag){
        trienode *cur=root;
      for(int i=18;i>=0;i--){
          int bit=(val>>i)&(1);
          if(!cur->child[bit]){
            cur->child[bit]=new trienode();
          }
          cur=cur->child[bit];
          cur->cnt+=flag;
      }
    }
    int qry(int val){
        trienode* cur=root;
        int maxi=0;
        for(int i=18;i>=0;i--){
            int bit=(val>>i)&1;
            int want=1-bit;
            if(cur->child[want] and cur->child[want]->cnt>0){
                maxi|=(1<<i);
                cur=cur->child[want];
            }
            else cur=cur->child[bit];
        }
        return maxi;
    } 
    void dfs(int u,const vector<vector<int>> &adj,const vector<vector<pair<int,int>>> &queries,vector<int> &ans){
        insert(u,1);
        for(auto &q:queries[u]){
            int val=q.first;
            int id=q.second;
            ans[id]=qry(val);
        }
        for(int v:adj[u]){
            dfs(v,adj,queries,ans);
        }
        insert(u,-1);
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n=parents.size();
        vector<vector<int>> adj(n);
        int rnode=-1;
        for(int i=0l;i<n;i++){
            if(parents[i]==-1){
                rnode=i;
            }
            else {
                adj[parents[i]].push_back(i);            
            }
        }
        int q=queries.size();
        vector<vector<pair<int,int>>> qry(n);
        for(int i=0;i<q;i++){
            qry[queries[i][0]].push_back({queries[i][1],i});
        }
        vector<int> ans(q);
        dfs(rnode,adj,qry,ans);
        return ans;
    }
};