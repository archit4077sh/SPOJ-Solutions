#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	long long t;
	cin>>t;
	while(t--)
	{
	long long x,n;
	cin>>x>>n;
	long long dp[n+1][10];
	for(long long i=0;i<n+1;i++)
		for(long long j=0;j<10;j++)
			dp[i][j]=0;
	for(long long i=0;i<=9;i++)
		dp[1][i]=1;
	for(long long i=2;i<=n;i++)
	{
		for(long long j=9;j>=0;j--)
		{
			for(long long k=0;k<=j;k++)
				{
					dp[i][j]+=dp[i-1][k];
				}
		}
	}
	long long sum=0;
	for(long long i=0;i<=9;i++)
	sum+=dp[n][i];
	cout<<x<<" "<<sum<<"\n";
	}	
}
