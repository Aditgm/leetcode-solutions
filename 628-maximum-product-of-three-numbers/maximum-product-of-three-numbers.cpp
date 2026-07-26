class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
     priority_queue<int,vector<int>,greater<int>>a;
     priority_queue<int>b;
     for(int i=0;i<3;i++){
        a.push(nums[i]);
        if(i!=2)b.push(nums[i]);
     }
     if(2<n&&nums[2]<=b.top()){
        b.push(nums[2]);b.pop();
     }
    //  cout<<b.size();
     for(int j=3;j<n;j++){
        int i=nums[j];

        if(i>=a.top()){
            a.pop();
            a.push(i);
        }
        if(i<=b.top()){
            b.pop();
            b.push(i);
        }
     }
    long long mx=1;
    int x=0;
    while(!a.empty()){
        x++;if(x==3) x=a.top();
        mx*=1ll*a.top();a.pop();
    }
    long long mx2=x;
    while(!b.empty()){
        mx2*=1ll*b.top();b.pop();
    }
    return max(mx,mx2);
    }
};