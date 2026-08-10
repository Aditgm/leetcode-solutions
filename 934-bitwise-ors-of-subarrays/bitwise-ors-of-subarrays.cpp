class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans,cur;
        int n=arr.size();
        for(int i=0;i<n;i++){
            unordered_set<int> nex;
            nex.insert(arr[i]);
            for(auto it:cur){
                nex.insert(arr[i]|it);
            }
            for(auto it:nex){
                ans.insert(it);
            }
            cur=nex;
        }
        return ans.size();
    }
};