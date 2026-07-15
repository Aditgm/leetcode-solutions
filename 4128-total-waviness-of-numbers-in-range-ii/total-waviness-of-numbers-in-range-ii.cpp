class Solution{
pair<long long,long long>memo[20][11][11][2][2];
string s;

pair<long long,long long>dfs(int idx,int prev2,int prev1,bool tight,bool is_lz){
if(idx==s.length())return{1,0};
if(memo[idx][prev2][prev1][tight][is_lz].first!=-1)return memo[idx][prev2][prev1][tight][is_lz];
int limit=tight?(s[idx]-'0'):9;
long long total_cnt=0;
long long total_wav=0;
for(int d=0;d<=limit;++d){
bool next_tight=tight&&(d==limit);
bool next_lz=is_lz&&(d==0);
int next_prev2=is_lz?10:prev1;
int next_prev1=next_lz?10:d;
int current_wave=0;
if(!is_lz&&prev2!=10&&prev1!=10){
if((prev1>prev2&&prev1>d)||(prev1<prev2&&prev1<d)){
current_wave=1;
}
}
auto[child_cnt,child_wav]=dfs(idx+1,next_prev2,next_prev1,next_tight,next_lz);
total_cnt+=child_cnt;
total_wav+=child_wav+(child_cnt*current_wave);
}
return memo[idx][prev2][prev1][tight][is_lz]={total_cnt,total_wav};
}

long long solve(long long num){
if(num<100)return 0;
s=to_string(num);
for(int i=0;i<20;++i)
for(int j=0;j<11;++j)
for(int k=0;k<11;++k)
for(int l=0;l<2;++l)
for(int m=0;m<2;++m)
memo[i][j][k][l][m]={-1,-1};
return dfs(0,10,10,true,true).second;
}

public:
long long totalWaviness(long long num1,long long num2){
return solve(num2)-solve(num1-1);
}
};