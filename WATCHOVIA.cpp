#include<bits/stdc++.h>
using namespace std;
long long k,m;
vector<long long>wt,val;

long long dp[55][10005];

long long rec(long long idx,long long remw)
{
    if(idx==m+1)
        return 0;
    if(remw<0)
        return 0;
    if(dp[idx][remw]!=-1)
        return dp[idx][remw];
    if(remw<wt[idx])
    {
        long long p1=rec(idx+1,remw);
        return dp[idx][remw]=p1;
    }
    else
    {
    long long p1=rec(idx+1,remw-wt[idx])+val[idx];
    long long p2=rec(idx+1,remw);
    return dp[idx][remw]=max(p1,p2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        long long i,j;
            for(i=0;i<55;i++)
            for(j=0;j<10005;j++)
            dp[i][j]=-1;
    cin>>k>>m;
    wt.resize(m+1);
    val.resize(m+1);
    for(i=1;i<=m;i++)
        cin>>wt[i]>>val[i];
    rec(1,k);
    cout<<"Hey stupid robber, you can get "<<dp[1][k]<<".\n";}
}
