class Solution {
public:
    string countOfAtoms(string formula) {
       stack<map<string,int>> st;
       st.push(map<string,int>());
       int n=formula.size();
       int i=0;
       while(i<n){
        if(formula[i]=='('){
            st.push(map<string,int>());
            i++;
        }
        else if(formula[i]==')'){
            i++;
            int sta=i;
            while(i<n and isdigit(formula[i])) i++;
            int multi=(i==sta)?1:stoi(formula.substr(sta,i-sta));
            map<string,int> top=st.top();st.pop();
            for(const auto&[atom,cnt]:top){
                st.top()[atom]+=cnt*multi;
            }
        }
        else{
            int sta=i++;
            while(i<n and islower(formula[i])) i++;
            string name=formula.substr(sta,i-sta);
            sta=i;
            while(i<n and isdigit(formula[i])) i++;
            int cnt=(i==sta)?1:stoi(formula.substr(sta,i-sta));
            st.top()[name]+=cnt;
        }
       }  
       string res="";
       for(auto [name,cnt]:st.top()){
        res+=name;
        if(cnt>1) res+=to_string(cnt);
       }
       return res;
    }
};