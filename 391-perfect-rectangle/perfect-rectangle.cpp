class Solution {
public:
    #define ll long long
    #define pii pair<int,int>
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int minx=INT_MAX,miny=INT_MAX,maxx=INT_MIN,maxy=INT_MIN;
        ll area=0;
        set<pair<int,int>> corners;
        for(auto rect:rectangles){
            minx=min(minx,rect[0]);
            miny=min(miny,rect[1]);
            maxx=max(maxx,rect[2]);
            maxy=max(maxy,rect[3]);
            area+=(ll)(rect[2]-rect[0])*(rect[3]-rect[1]);
            pair<int,int> p1={rect[0],rect[1]};
            pair<int,int> p2={rect[0],rect[3]};
            pair<int,int> p3={rect[2],rect[1]};
            pair<int,int> p4={rect[2],rect[3]};
            for(auto p:{p1,p2,p3,p4}){
                if(corners.count(p)) corners.erase(p);
                else corners.insert(p);
            }
        }
        pii gp1={minx,miny};
        pii gp2={minx,maxy};
        pii gp3={maxx,maxy};
        pii gp4={maxx,miny};
        if(corners.size()!=4 or !corners.count(gp1) or !corners.count(gp2) or !corners.count(gp3) or !corners.count(gp4)) return 0;
        ll exparea=(ll)(maxx-minx)*(maxy-miny);
        return area==exparea;
    }
};