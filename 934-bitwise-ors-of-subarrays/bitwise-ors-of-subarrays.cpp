class Solution {
public:
    #define vi vector<int>
    #define pb push_back
    int subarrayBitwiseORs(vector<int>& arr) {
        vi ans,cur;
        int n=arr.size();
        for(int i=0;i<n;i++){
            vi nex;
            nex.pb(arr[i]);
            for(auto it:cur){
                nex.pb(arr[i]|it);
            }
            sort(nex.begin(),nex.end());
            nex.erase(unique(nex.begin(),nex.end()),nex.end());
            for(auto it:nex){
                ans.pb(it);
            }
            cur=move(nex);
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans.size();
    }
};