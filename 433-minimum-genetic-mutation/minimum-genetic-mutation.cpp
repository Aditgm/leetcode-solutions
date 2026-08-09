class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(),bank.end());
        queue<pair<string,int>> q;
        q.push({startGene,0});
        vector<char> dir={'A','C','G','T'};
        while(!q.empty()){
           auto u=q.front();q.pop();
           if(u.first==endGene) return u.second;
           string t=u.first;
           for(int i=0;i<8;i++){
             char og=t[i];
             for(char it:dir){
                if(it==og) continue;
                t[i]=it;
                if(st.count(t)){
                    st.erase(t);
                    q.push({t,u.second+1});
                }
             }
             t[i]=og;
           }
        }
        return -1;
    }
};