class Solution {
public:
    void dfs(vector<vector<int>> &grid,int r,int c,int n,queue<pair<int,int>> &q){
        if(r<0 or r>=n or c<0 or c>=n or grid[r][c]!=1) return;
        grid[r][c]=2;
        q.push({r,c});
        dfs(grid,r-1,c,n,q);
        dfs(grid,r+1,c,n,q);
        dfs(grid,r,c-1,n,q);
        dfs(grid,r,c+1,n,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        bool ok=0;
        for(int i=0;i<n and !ok;i++){
            for(int j=0;j<n and !ok;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,n,q);
                    ok=1;
                }
            }
        }
        int steps=0;
        int dr[4]={0,1,0,-1};
        int dc[4]={1,0,-1,0};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto [r,c]=q.front();q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 and nr<n and nc>=0 and nc<n){
                        if(grid[nr][nc]==1){
                            return steps;
                        }
                        if(grid[nr][nc]==0){
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};