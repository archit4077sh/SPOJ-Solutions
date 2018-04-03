#include<bits/stdc++.h>
using namespace std;
long long n;
long long rec(long long arr[],long long dp[],long long i)
{
    long long ans=0;
    if(i==n)
        return 1;
    if(i==n-1)
    {
        if(arr[n-1]!=0)
        dp[n-1]=1;
        else
        dp[n-1]=0;
        return dp[n-1];
    }
    if(dp[i]!=-1)
        return dp[i];
    if(arr[i]==0)
        {
            dp[i]=0;
            return 0;
        }
    if(arr[i]*10+arr[i+1]>26)
    {
        ans+=rec(arr,dp,i+1);
        dp[i]=ans;
        return dp[i];
    }
    if(arr[i]*10+arr[i+1]<27)
    {
        ans=ans+rec(arr,dp,i+1)+rec(arr,dp,i+2);
        dp[i]=ans;
        return dp[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
    string s;
    cin>>s;
    n=s.size();
    if(n==1)
    {
        if(s[0]=='0')
            break;
    }
    long long arr[n];
    long long dp[n];
    for(long long i=0;i<n;i++)
    {
        arr[i]=s[i]-'0';
        dp[i]=-1;
    }
    rec(arr,dp,0);
    cout<<dp[0]<<"\n";
    }
}
