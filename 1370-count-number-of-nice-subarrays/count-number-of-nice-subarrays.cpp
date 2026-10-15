class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        /* approach:
           step 1: first we are modifying this to <(k)-<(k-1) o get exact k 
        */
        int n=a.size();
        auto atmost=[&](int x)->int{
            int cnt=0;
            int rng=0;
            int l=0;
            for(int r=0;r<n;r++){
               if(a[r]%2==1) cnt++;
               while(cnt>x){
                if(a[l]%2) cnt--;
                l++;
               } 
               rng+=(r-l+1);
            }
            return rng;
        };
        return atmost(k)-atmost(k-1);
    }
};