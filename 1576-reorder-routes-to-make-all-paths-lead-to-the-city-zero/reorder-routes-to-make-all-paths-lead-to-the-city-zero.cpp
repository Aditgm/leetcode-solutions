class Solution {
public:
    int dfs(int cur,int par,vector<vector<pair<int,int>>> &adj){
        int tot=0;
        for(auto &[nei,cost]:adj[cur]){
            if(nei!=par){
                tot+=cost+dfs(nei,cur,adj);
            }
        }
        return tot;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        return dfs(0,-1,adj);
    }
};