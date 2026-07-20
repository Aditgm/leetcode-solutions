class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int h=0;
        int n=citations.size();
        while(h<n and citations[h]>h){
            h++;
        }
        return h;
    }
};