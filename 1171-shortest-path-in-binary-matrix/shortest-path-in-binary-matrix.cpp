class Solution {
public:
    int dr[8]={-1,0,1,0,1,1,-1,-1};
    int dc[8]={0,1,0,-1,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0 or grid[0][0]==1 or grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int len=1;
        while(!q.empty()){
           int sz=q.size();
           while(sz--){
              auto [r,c]=q.front();q.pop();
              if(r==n-1 and c==n-1) return len;
             for(int i=0;i<8;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr>=0 and nr<n and nc>=0 and nc<n and grid[nr][nc]==0){
                    q.push({nr,nc});
                    grid[nr][nc]=1;
                }
             }
           }
           len++;
        }
        return -1;
    }
};