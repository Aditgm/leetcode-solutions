class RandomizedSet {
public:
#define vi vector<int>
    vi nums;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return 0;
        mp[val]=nums.size();
        nums.push_back(val);
        return 1;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return 0;
        int id=mp[val];
        int lst=nums.back();
        nums[id]=lst;
        mp[lst]=id;
        nums.pop_back();
        mp.erase(val);
        return 1;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */