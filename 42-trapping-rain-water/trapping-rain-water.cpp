class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int lft=0,rght=n-1;
        int leftmax=0,rightmax=0;
        int tot=0;
        while(lft<rght){
            if(height[lft]<=height[rght]){
                if(height[lft]>=leftmax){
                    leftmax=height[lft];
                }
                else{
                    tot+=leftmax-height[lft];
                }
                lft++;
            }
            else{
                if(height[rght]>=rightmax){
                    rightmax=height[rght];
                }
                else{
                    tot+=rightmax-height[rght];
                }
                rght--;
            }
        }
        return tot;
    }
};