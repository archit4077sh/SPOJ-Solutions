#include<bits/stdc++.h>
using namespace std;

int dp[6105][6105];
string s;
int rec(int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return dp[i][j]=0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]=rec(i+1,j-1);
    }
    else
    {
        //return dp[i][j]=min(rec(i,j-1),rec(i+1,j))+1;
    return dp[i][j]=rec(i,j-1)+1;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    for(int i=0;i<6105;i++)
        for(int j=0;j<6105;j++)
        dp[i][j]=-1;

    cin>>s;
    rec(0,s.size()-1);
    cout<<dp[0][s.size()-1]<<"\n";
    }
}
