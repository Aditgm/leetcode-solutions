class StockSpanner {
public:
    vector<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt=1;
        while(!st.empty() and st.back().first<=price){
            cnt+=st.back().second;
            st.pop_back();
        }
        st.push_back({price,cnt});
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */