class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int maxi=0;
        for(auto &it:edges){
            maxi=max(maxi,it[2]);
        }
        int lo=0,hi=maxi;
        int ans=-1;
        auto chk=[&](int w)->bool{
            vector<vector<int>> adj(n);
            for(const auto &e:edges){
                if(e[2]<=w){
                    adj[e[1]].push_back(e[0]);
                }
            }
            vector<bool> vis(n,0);
            int cnt=0;
            queue<int> q;
            vis[0]=1;
            q.push(0);
            cnt++;
            while(!q.empty()){
                auto cur=q.front();
                q.pop();
                for(auto it:adj[cur]){
                    if(!vis[it]){
                        vis[it]=1;
                        cnt++;
                        q.push(it);
                    }
                }
            }
            return cnt==n;
        };
        while(lo<=hi){
            int mid=(hi-lo)/2+lo;
            if(chk(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};