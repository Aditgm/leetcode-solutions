class Solution {
public:
    #define vi vector<int>
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vi pref(n+2,0),ans;
        int m=bookings.size();
        for(int i=0;i<m;i++){
            pref[bookings[i][0]]+=bookings[i][2];
            pref[bookings[i][1]+1]-=bookings[i][2];
        }
        for(int i=1;i<=n;i++){
            pref[i]+=pref[i-1];
        }
        for(int i=1;i<=n;i++){
            ans.push_back(pref[i]);
        }
        return ans;
    }
};