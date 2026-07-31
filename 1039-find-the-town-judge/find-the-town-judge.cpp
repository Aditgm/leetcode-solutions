class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdeg(n+1,0),indeg(n+1,0);
        for(auto it:trust){
            outdeg[it[0]]++;
            indeg[it[1]]++;
        }
        int node=-1;
        for(int i=0;i<n;i++){
            if(outdeg[i+1]==0 and indeg[i+1]==n-1) node=i+1;
        }
        return node;
    }
};