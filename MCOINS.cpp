#include<bits/stdc++.h>
using namespace std;
int dp[1000001];
int main()
{
    int k,l,m,i;
    cin>>k>>l>>m;
    int arr[m+1];
    for(i=0;i<1000001;i++)
        dp[i]=-1;

    dp[0]=0;
    dp[1]=1;
    dp[k]=1;
    for(i=2;i<1000001;i++)
    {
        if(dp[i]==-1)
        {
            if(i-k>=0 && i-l>=0)
            {
            if(dp[i-1]==0 || dp[i-k]==0 || dp[i-l]==0)
                dp[i]=1;
            else
                dp[i]=0;
            }
            if(i-k>=0 && i-l<0)
            {
            if(dp[i-1]==0 || dp[i-k]==0)
                dp[i]=1;
            else
                dp[i]=0;
            }
            if(i-k<0 && i-l>=0)
            {
            if(dp[i-1]==0 || dp[i-l]==0)
                dp[i]=1;
            else
                dp[i]=0;
            }
            if(i-k<0 && i-l<0)
            {
            if(dp[i-1]==0)
                dp[i]=1;
            else
                dp[i]=0;
            }
        }
    }



    for(i=1;i<=m;i++)
        {
            cin>>arr[i];
            if(dp[arr[i]])
                cout<<"A";
            else
                cout<<"B";
        }


}
