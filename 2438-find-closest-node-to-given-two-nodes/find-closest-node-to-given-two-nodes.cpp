class Solution {
public:
   #define vi vector<int> 
   #define vvi vector<vi>
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vi disa(n+1,-1),disb(n+1,-1);
        queue<int> q;
        q.push(node1);
        disa[node1]=0;
        while(!q.empty()){
           auto u=q.front();q.pop();
           int v=edges[u];
           if(v!=-1 and disa[v]==-1){
            disa[v]=disa[u]+1;
            q.push(v);
           }
        }
        queue<int> q1;
        q1.push(node2);
        disb[node2]=0;
        while(!q1.empty()){
            auto u=q1.front();q1.pop();
            int v=edges[u];
            if(v!=-1 and disb[v]==-1){
                disb[v]=disb[u]+1;
                q1.push(v);
            }
        }
        int mini=INT_MAX,bst=-1;
        for(int i=0;i<n;i++){
            if(disa[i]!=-1 and disb[i]!=-1 and max(disa[i],disb[i])<mini){
               mini=max(disa[i],disb[i]);
               bst=i;
            }
        }
        return bst;
    }
};