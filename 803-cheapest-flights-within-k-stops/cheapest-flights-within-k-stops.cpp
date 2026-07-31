class Solution {
public:
    #define  vi vector<int>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vi dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>> q;
        q.push({src,0});
        int cnt=0;
        while(!q.empty() and cnt<=k){
           int sz=q.size();
           while(sz--){
             auto [node,cost]=q.front();
             q.pop();
             for(auto nei:adj[node]){
                 int costi=nei.second;
                 int nodee=nei.first;
                 if(dist[nodee]>costi+cost){
                    dist[nodee]=costi+cost;
                    q.push({nodee,dist[nodee]});
                 }
             }
           }
           cnt++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};