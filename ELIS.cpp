#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int arr[n+1],dp[n+1];
    for(i=1;i<=n;i++)
        {
        cin>>arr[i];
        dp[i]=1;
        }
    int maxi=1;
    for(i=1;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(arr[i]>arr[j])
            if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    if(maxi<dp[i])
                        maxi=dp[i];
                }
        }
    }
    cout<<maxi;
}
