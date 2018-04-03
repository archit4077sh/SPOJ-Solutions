#include<bits/stdc++.h>
using namespace std;

string s1,s2;
int dp[2005][2005];

int rec(int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==s1.size())
    {
        if(j==s2.size())
            return 0;
        else
            return abs(s2.size()-j);

    }
    if(j==s2.size())
    {
        if(i!=s1.size())
        return abs(s1.size()-i);
    }
    if(s1[i]==s2[j])
    {
        return dp[i][j]=rec(i+1,j+1);
    }
    else
    {
        int p1=rec(i+1,j+1)+1;
        int p2=rec(i+1,j)+1;
        int p3=rec(i,j+1)+1;
       // cout<<p1<<" "<<p2<<" "<<p3<<"\n";
        return dp[i][j]=min(p1,min(p2,p3));
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<2005;i++)
            for(int j=0;j<2005;j++)
            dp[i][j]=-1;
        cin>>s1>>s2;
        rec(0,0);
        cout<<dp[0][0]<<"\n";
    }
}
