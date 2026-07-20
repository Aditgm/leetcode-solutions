class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int tot=n*m;
        k%=tot;
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int old=i*m+j;
                int newi=(old+k)%tot;
                int nr=newi/m;
                int nc=newi%m;
                res[nr][nc]=grid[i][j];
            }
        }
        return res;
    }
};