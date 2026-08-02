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
            vector<int> stack={0};
            int cnt=0;
            vis[0]=1;
            cnt++;
            while(!stack.empty()){
                int cur=stack.back();
                stack.pop_back();
                for(int nex:adj[cur]){
                    if(!vis[nex]){
                        vis[nex]=1;
                        cnt++;
                        stack.push_back(nex);
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