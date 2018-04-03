#include<bits/stdc++.h>
using namespace std;
#define INF 6000000000
long long dp[10001];
long long wetval[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
    long long e,f,n;
    cin>>e>>f;
    long long wt=f-e;
    cin>>n;
    long long i,j;
    for(i=0;i<10001;i++)
    {
    dp[i]=INF;
    wetval[i]=INF;
    }
    for(i=1;i<=n;i++)
    {
    long long x,y;
    cin>>x>>y;
    wetval[y]=min(x,wetval[y]);
    }
    dp[0]=0;
    for(i=1;i<=10001;i++)
        for(j=1;j<10001;j++)
        {
            if(wetval[j]!=INF)
            {
            if(j<=i)
            dp[i]=min(dp[i],dp[i-j]+wetval[j]);
            else
                break;
            }
        }
    if(dp[wt]!=INF)
    cout<<"The minimum amount of money in the piggy-bank is "<<dp[wt]<<".\n";
    else
        cout<<"This is impossible.\n";
    }
}
