class Solution {
public:
    string removeStars(string s){
        vector<char> st;
        for(auto c:s){
            if(c=='*'){if(!st.empty()) st.pop_back();}
            else st.push_back(c);
        }
        string ans(st.begin(),st.end());
        return ans;
    }
};