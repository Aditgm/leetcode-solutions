class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int cnt=0;
        while(tx>=sx and ty>=sy){
            if(tx==sx and ty==sy) return cnt;
            if(tx==ty){
                if(sx==0){
                    tx=0;
                }
                else if(sy==0){
                    ty=0;
                }
                else return -1;
                cnt++;
                continue;
            }
            if(tx>ty){
                if(tx>=2*ty){
                    if(tx&1){
                        return -1;
                    }
                    tx/=2;
                }
                else tx-=ty;
            }
            else{
                if(ty>=2*tx){
                    if(ty&1) return -1;
                    ty/=2;
                }
                else ty-=tx;
            }
            cnt++;
        }
        return -1;
    }
};