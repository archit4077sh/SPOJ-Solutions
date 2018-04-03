#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll rec(ll mat[][4],ll dp[][4],ll i,ll j)
{
    if(dp[i][j]!=LLONG_MAX)
    {
        return dp[i][j];
    }
    ll ans1,ans2,ans3,ans4;
    if(i==2)
    {
    if(j==1)
    {
    dp[2][1]=mat[2][1]+mat[1][2];
    return dp[i][j];
    }
    if(j==2)
    {
    dp[2][2]=mat[i][j]+min(mat[1][2],min(mat[1][2]+mat[1][3],mat[1][2]+mat[2][1]));
    return dp[i][j];
    }
    if(j==3)
    {
    dp[i][j]=mat[i][j]+min(mat[1][2],min(min(mat[1][2]+mat[1][3],mat[1][2]+mat[2][2]),mat[1][2]+mat[2][1]+mat[2][2]));
    return dp[i][j];
    }
    }
    else
    {
    if(j==1)
    {
    ans2=rec(mat,dp,i-1,1);
    ans3=rec(mat,dp,i-1,2);
    dp[i][j]=mat[i][j]+min(ans2,ans3);
    return dp[i][j];
    }
    if(j==2)
    {
    ans1=rec(mat,dp,i-1,1);
    ans2=rec(mat,dp,i-1,2);
    ans3=rec(mat,dp,i-1,3);
    ans4=rec(mat,dp,i,1);
    dp[i][j]=mat[i][j]+min(ans1,min(ans2,min(ans3,ans4)));
    return dp[i][j];
    }
    if(j==3)
    {
    ans1=rec(mat,dp,i-1,2);
    ans2=rec(mat,dp,i-1,3);
    ans3=rec(mat,dp,i,2);
    dp[i][j]=mat[i][j]+min(ans1,min(ans2,ans3));
    return dp[i][j];
    }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=0;
    while(1)
    {
    cin>>n;
    if(n==0)
        break;
    t++;
    ll mat[n+1][4],dp[n+1][4];
    ll i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<4;j++)
    {
        cin>>mat[i][j];
        dp[i][j]=LLONG_MAX;
    }
    dp[1][2]=mat[1][2];
    rec(mat,dp,n,2);
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<4;j++)
    {
        cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
    }*/
    cout<<t<<". "<<dp[n][2]<<"\n";
    }
}
