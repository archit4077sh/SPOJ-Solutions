#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> maxi(pair<long long,long long>p1,pair<long long,long long>p2)
{
    if(p1.first>p2.first)
        return p1;
    if(p1.first<p2.first)
        return p2;
    if(p1.first==p2.first)
    {
        if(p1.second>p2.second)
            return p2;
        else
            return p1;
    }
}
long long n,bug;
vector<pair<long long,long long> >vec;
vector<vector<pair<long long,long long> > >dp(105,vector<pair<long long,long long> >(505,{-1,-1}));
pair<long long,long long> rec(long long idx,long long rembug)
{
    if(idx==n+1)
        return make_pair(0,bug-rembug);
    if(dp[idx][rembug].first!=-1)
        return dp[idx][rembug];
    pair<long long,long long> p1,p2;
    if(rembug-vec[idx].first>=0)
    {
    p1=rec(idx+1,rembug-vec[idx].first);
    long long x=vec[idx].second+p1.first;
    long long y=p1.second;
    p1=make_pair(x,y);
    p2=rec(idx+1,rembug);
    }
    else
        return dp[idx][rembug]=rec(idx+1,rembug);
    return dp[idx][rembug]=maxi(p1,p2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
    long long i;
    cin>>bug>>n;
    if(n==0 && bug==0)
        return 0;
    for(i=0;i<105;i++)
        for(long long j=0;j<505;j++)
        dp[i][j].first=dp[i][j].second=-1;
    vec.resize(n+1);
    for(i=1;i<=n;i++)
    {
        long long x,y;
        cin>>x>>y;
        vec[i].first=x;
        vec[i].second=y;
    }
    rec(1,bug);
    cout<<dp[1][bug].second<<" "<<dp[1][bug].first<<"\n";
    }
}
