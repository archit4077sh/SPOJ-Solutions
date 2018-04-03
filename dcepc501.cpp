#include<bits/stdc++.h>
using namespace std;
long long  n;
long long rec(long long m[],long long dp[],long long i)
{
    if(dp[i]!=-1)
        return dp[i];
    dp[i]=max(m[i]+rec(m,dp,i+2),max(m[i]+m[i+1]+rec(m,dp,i+4),m[i]+m[i+1]+m[i+2]+rec(m,dp,i+6)));
}
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
    long long n;
    cin>>n;
    long long m[n+4];
    long long i,j;
    for(i=1;i<=n;i++)
        cin>>m[i];
    m[n+3]=m[n+2]=m[n+1]=0;
    long long dp[n+7];
    for(i=1;i<=n;i++)
        dp[i]=-1;
    dp[0]=dp[n+6]=dp[n+5]=dp[n+4]=dp[n+3]=dp[n+2]=dp[n+1]=0;
    rec(m,dp,1);
    cout<<dp[1]<<"\n";
    }
}
