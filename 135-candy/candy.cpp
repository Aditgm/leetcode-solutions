class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int ans=1;
        int up=0,down=0,peak=0;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                up+=1;
                ans+=up+1;
                down=0;
                peak=up;
            }
            else if(ratings[i]==ratings[i-1]){
                ans++;
                down=0;up=0;peak=0;
            }
            else{
                down+=1;
                up=0;
                ans+=down;
                if(down>peak) ans++;
            }
        }
        return ans;
    }
};