class Solution {
public:
    #define vi vector<int>
    #define pb push_back
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vi pref(n+1,0),left(n+1,0),right(n+1,0);
        int lft=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*') cnt++;
            if(s[i]=='|'){
                lft=i;
            }
            pref[i]=cnt;
            left[i]=lft;
        }
        int rght=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|'){
                rght=i;
            }
            right[i]=rght;
        }
        vi ans;
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int l1=right[l],r1=left[r];
            if(l1==-1 or r1==-1 or l1>=r1) ans.pb(0);
            else{
                ans.pb(pref[r1]-pref[l1]);
            }
        }
        return ans;
    }
};