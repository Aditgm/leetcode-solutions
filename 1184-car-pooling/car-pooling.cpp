class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> pref(1002,0);
        for(int i=0;i<n;i++){
            pref[trips[i][1]]+=trips[i][0];
            pref[trips[i][2]]-=trips[i][0];
        }
        int lo=trips[0][1],hi=trips[0][2];
        for(int i=1;i<n;i++){
            lo=min(lo,trips[i][1]);
            hi=max(hi,trips[i][2]);
        }
        for(int i=lo;i<=hi;i++){
            pref[i+1]+=pref[i];
        }
        for(int i=lo;i<=hi;i++){
            if(pref[i]>capacity) return 0;
        }
        return 1;
    }
};