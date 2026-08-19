class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
      unordered_map<int,unordered_set<int>> st;
      for(const auto &it:reservedSeats){
        st[it[0]].insert(it[1]);
      }
      int ans=2*n;
      for(const auto &[row,seats]:st){
        bool lft=1;
        for(int s=2;s<=5;s++){
            if(seats.count(s)){
                lft=0;break;
            }
        }
        bool right=1;
        for(int s=6;s<=9;s++){
            if(seats.count(s)){
                right=0;break;
            }
        }
        bool mid=1;
        for(int s=4;s<=7;s++){
            if(seats.count(s)){
                mid=0;break;
            }
        }
        if(lft and right){
            continue;
        }
        else if(lft or right or mid){
            ans-=1;
        }
        else {
            ans-=2;
        }
      }
      return ans;
    }
};