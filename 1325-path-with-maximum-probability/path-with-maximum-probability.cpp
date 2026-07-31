class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        } 
        priority_queue<pair<double,int>> pq;
        vector<double> maxi(n,0.0);
        maxi[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int curr=it.second;
            double prb=it.first;
            if(curr==end_node) return prb;
            if(prb<maxi[curr]) continue;
            for(auto &[node,probi]:adj[curr]){
                double nextp=prb*probi;
                if(nextp>maxi[node]){
                maxi[node]=nextp;
                pq.push({maxi[node],node});
            }
          }
        }
        return 0.0;
    }
};