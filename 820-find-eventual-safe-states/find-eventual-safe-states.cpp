class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n);
        vector<int> indeg(n,0);
        for(int u=0;u<n;u++){
            for(int v:graph[u]){
                rev[v].push_back(u);
                indeg[u]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<bool> issafe(n,0);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            issafe[u]=1;
            for(int v:rev[u]){
                if(--indeg[v]==0) q.push(v);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(issafe[i]) ans.push_back(i);
        }
        return ans;
    }
};