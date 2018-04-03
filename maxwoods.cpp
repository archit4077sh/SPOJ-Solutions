#include<bits/stdc++.h>
using namespace std;
long long m,n,mat[205][205];
long long dp[205][205];
bool isvalid(long long i,long long j)
{
    if(i<=m && i>=1 && j>=1 && j <=n)
        return true;
    return false;
}
long long rec(long long i,long long j)
{
    long long p1,p2;

    if(isvalid(i,j)==false)
        {
            //cout<<"yes";
            return 0;
        }

    if(mat[i][j]==-1)
        {
            //cout<<"yes11";
            dp[i][j]=0;
            cout<<" i is "<<i<<" j is "<<j<<" dp is "<<dp[i][j]<<"\n";
            return dp[i][j];
        }

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(i%2!=0)
    {
    p1=rec(i,j+1);
    p2=rec(i+1,j);
    }
    else
    {
    p1=rec(i,j-1);
    p2=rec(i+1,j);
    }
    if(mat[i][j]==1)
    dp[i][j]=max(p1,p2)+1;
    if(mat[i][j]==0)
    dp[i][j]=max(p1,p2);
    cout<<" i is "<<i<<" j is "<<j<<" dp is "<<dp[i][j]<<"\n";
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
    long long i,j;
    char x;
    for(i=0;i<205;i++)
        for(j=0;j<205;j++)
            dp[i][j]=-1;
    cin>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
        cin>>x;
        if(x=='T')
            mat[i][j]=1;
        if(x=='#')
            mat[i][j]=-1;
        if(x=='0')
            mat[i][j]=0;
        }
    cout<<rec(1,1);
    cout<<dp[1][1]<<"\n";
    }
}
