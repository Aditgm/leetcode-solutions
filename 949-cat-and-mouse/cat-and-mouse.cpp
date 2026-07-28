class Solution {
public:
    #define vi vector<int>
    int catMouseGame(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<vi>> dp(n,vector<vi>(n,vi(2,0)));
        vector<vector<vi>> outdeg(n,vector<vi>(n,vi(2,0)));
        queue<vi> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                outdeg[i][j][0]=graph[i].size();
                outdeg[i][j][1]=graph[j].size();
                for(int nex:graph[j]){
                    if(nex==0) outdeg[i][j][1]--;
                }
            }
        }
        for(int i=1;i<n;i++){
            dp[i][i][0]=2;
            dp[i][i][1]=2;
            q.push({i,i,0,2});
            q.push({i,i,1,2});
            dp[0][i][0]=1;
            dp[0][i][1]=1;
            q.push({0,i,0,1});
            q.push({0,i,1,1});
        }
        while(!q.empty()){
            vi cur=q.front();
            q.pop();
            int m=cur[0],c=cur[1],turn=cur[2],winner=cur[3];
            if(turn==0){
                for(int prv:graph[c]){
                    if(prv==0) continue;
                    if(dp[m][prv][1]==0){
                        if(winner==2){
                            dp[m][prv][1]=2;
                            q.push({m,prv,1,2});
                        }
                        else{
                            outdeg[m][prv][1]--;
                            if(outdeg[m][prv][1]==0){
                               dp[m][prv][1]=1;
                               q.push({m,prv,1,1});
                            }
                        }
                    }
                }
            }
            else{
                for(int prv:graph[m]){
                   if(dp[prv][c][0]==0){
                    if(winner==1){
                        dp[prv][c][0]=1;
                        q.push({prv,c,0,1});
                    }
                    else{
                        outdeg[prv][c][0]--;
                        if(outdeg[prv][c][0]==0){
                            dp[prv][c][0]=2;
                            q.push({prv,c,0,2});
                        }
                    }
                   }
                }
            }
        }
        return dp[1][2][0];
    }
};