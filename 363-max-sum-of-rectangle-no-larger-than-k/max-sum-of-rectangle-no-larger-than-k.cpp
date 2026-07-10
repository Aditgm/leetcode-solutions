class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            vector<int> rows(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    rows[k]+=matrix[k][j];
                }
                set<int> prefsum;
                prefsum.insert(0);
                int cur=0;
                for(int sum:rows){
                    cur+=sum;
                    auto it=prefsum.lower_bound(cur-k);
                    if(it!=prefsum.end()){
                        maxi=max(maxi,cur-*it);
                    }
                    prefsum.insert(cur);
                }
            }
        }
        return maxi;
    }
};