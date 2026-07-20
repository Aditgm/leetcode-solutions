class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> cnt(n+1,0);
        for(int c:citations){
           if(c>=n){
            cnt[n]++;
           } 
           else cnt[c]++;
        }
        int tot=0;
        for(int i=n;i>=0;i--){
            tot+=cnt[i];
            if(tot>=i) return i;
        }
        return 0;
    }
};