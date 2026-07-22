class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int n=a.length(),m=b.length();
        int i=n-1,j=m-1;
        int carry=0;
        while(i>=0 or j>=0 or carry){
            int sum=0;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            sum+=carry;
            res+=((sum%2)+'0');
            carry=sum/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};