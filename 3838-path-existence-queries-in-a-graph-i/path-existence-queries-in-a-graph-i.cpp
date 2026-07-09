class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,0);
        int cur=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                cur++;
            }
            comp[i]=cur;
        }
        vector<bool> res;
        for(auto q:queries){
            res.push_back(comp[q[0]]==comp[q[1]]);
        }
        return res;
    }
};