class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if((board[i][j]^board[i+1][j]^board[i][j+1]^board[i+1][j+1])!=0) return -1;
            }
        }
        int rowsum=0,colsum=0;
        int rowswap=0,colswap=0;
        for(int i=0;i<n;i++){
            rowsum+=board[0][i];
            colsum+=board[i][0];
            if(board[0][i]==i%2) rowswap++;
            if(board[i][0]==i%2) colswap++;
        }
        if(rowsum<n/2 or rowsum>(n+1)/2) return -1;
        if(colsum<n/2 or colsum>(n+1)/2) return -1;
        if(n%2){
            if((rowswap)%2!=0) rowswap=n-rowswap;
            if((colswap%2)) colswap=n-colswap;
        }
        else{
            rowswap=min(rowswap,n-rowswap);
            colswap=min(colswap,n-colswap);
        }
        return (colswap+rowswap)/2;
    }
};