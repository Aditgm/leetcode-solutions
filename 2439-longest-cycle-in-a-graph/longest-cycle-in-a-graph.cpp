class Solution {
public:
    #define pb push_back
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
           if(edges[i]!=-1) adj[i].pb(edges[i]);
        }
        vector<int> timer(n,0);
        int tim=1,len=-1;
        for(int i=0;i<n;i++){
            if(timer[i]>0) continue;
            int st=tim;
            int curr=i;
            while(curr!=-1 and timer[curr]==0){
                timer[curr]=tim++;
                if(!adj[curr].empty()){
                    curr=adj[curr][0];
                }
                else curr=-1;
            }
            if(curr!=-1 and timer[curr]>=st){
                len=max(len,tim-timer[curr]);
            }
        }
        return len;
    }
};