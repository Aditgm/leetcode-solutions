class SummaryRanges {
public:
    map<int,int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        auto it=mp.upper_bound(value);
        auto prv=it;
        if(prv!=mp.begin()){
            --prv;
        }
        else prv=mp.end();
        if(prv!=mp.end() and prv->first<=value and value<=prv->second) return;
        bool mergeprv=(prv!=mp.end() and prv->second+1==value);
        bool mergenext=(it!=mp.end() and it->first-1==value);
        if(mergeprv and mergenext){
            prv->second=it->second;
            mp.erase(it);
        }
        else if(mergeprv){
            prv->second=value;
        }
        else if(mergenext){
            mp[value]=it->second;
            mp.erase(it);
        }
        else{
            mp[value]=value;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */