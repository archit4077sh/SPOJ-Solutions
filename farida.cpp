#include<bits/stdc++.h>
using namespace std;
long long rec(long long arr[],long long dp[],int i)
{
	if(i==0)
	return 0;
    if(dp[i]!=-1)
        return dp[i];
    long long mon=arr[i]+max(rec(arr,dp,i-2),rec(arr,dp,i-3));
    return dp[i]=mon;
}
int main()
{
    long long t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
    long long n,i;
    cin>>n;
    long long arr[n+1];
    for(i=1;i<=n;i++)
        cin>>arr[i];
    long long dp[n+1];
    for(i=1;i<n+1;i++)
        dp[i]=-1;
    long long ans=-1;
        dp[1]=arr[1];
        dp[2]=arr[2];
        dp[3]=arr[3]+arr[1];
    rec(arr,dp,n);
    rec(arr,dp,n-1);
    for(i=1;i<=n;i++)
    ans=max(ans,dp[i]);
    if(n!=0)
    cout<<"Case "<<j<<": "<<ans<<"\n";
    else
    cout<<"Case "<<j<<": "<<0<<"\n";
    }zzzz
    return 0;
}
