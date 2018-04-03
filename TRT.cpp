#include<bits/stdc++.h>
using namespace std;
vector<long long>arr;
long long n;
long long dp[2005][2005];
long long rec(long long idx1,long long idx2)
{
    if(dp[idx1][idx2]!=-1)
        return dp[idx1][idx2];
    long long age=n+idx1-idx2;
    if(idx1==idx2)
        return arr[idx1]*(age);
    long long p1=rec(idx1+1,idx2)+arr[idx1]*age;
    long long p2=rec(idx1,idx2-1)+arr[idx2]*age;
    return dp[idx1][idx2]=max(p1,p2);
}
int main()
{
    for(long long i=0;i<2005;i++)
        for(long long j=0;j<2005;j++)
        dp[i][j]=-1;
    cin>>n;
    arr.resize(n+1);
    for(long long i=1;i<=n;i++)
        cin>>arr[i];
    cout<<rec(1,n);
}
