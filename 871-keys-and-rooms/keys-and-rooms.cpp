class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,0);
        queue<int> q;
        vis[0]=1;
        q.push(0);
        int open=1;
        while(!q.empty()){
            auto it=q.front();q.pop();
            vis[it]=1;
            for(auto nei:rooms[it]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push(nei);
                    open++;
                }
            }
        }
        return (open==n);
    }
};