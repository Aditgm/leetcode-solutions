class Solution {
public:
    bool isValid(string code) {
        stack<string> st;
        int i=0;
        int n=code.size();
        while(i<n){
            if(i>0 and st.empty()) return 0;
            if(code.compare(i,9,"<![CDATA[")==0){
                int j=code.find("]]>",i+9);
                if(j==string::npos) return 0;
                i=j+3;
            }
            else if(code.compare(i,2,"</")==0){
                int j=code.find('>',i+2);
                if(j==string::npos) return 0;
                string tag=code.substr(i+2,j-i-2);
                if(st.empty() or st.top()!=tag) return 0;
                st.pop();
                i=j+1;
            }
            else if(code[i]=='<'){
                int j=code.find('>',i+1);
                if(j==string::npos) return 0;
                string tag=code.substr(i+1,j-i-1);
                if(tag.length()<1 or tag.length()>9) return 0;
                for(char c:tag){
                    if(!isupper(c)) return 0;
                }
                st.push(tag);
                i=j+1;
            }
            else i++;
        }
        return st.empty();
    }
};