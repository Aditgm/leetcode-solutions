class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
       }  
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
        vector<int> dist(n,-1);
        vector<int> par(n,-1);
        queue<int> q;
        dist[i]=0;
        q.push(i);
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            for(auto it:adj[cur]){
                if(dist[it]==-1){
                    dist[it]=dist[cur]+1;
                    par[it]=cur;
                    q.push(it);
                }
                else if(it!=par[cur]){
                    mini=min(mini,dist[it]+dist[cur]+1);
                }
            }
        }
       }
       return mini==INT_MAX?-1:mini;
    }
};