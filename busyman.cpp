#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    pair< int , int> p[n];
    //cout<<"stop1";
    int i;
    int x,y;
    //cout<<"stop1";
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        p[i]=make_pair(y,x);
    }
    sort(p,p+n);
    y=1;
    x=p[0].first;
    for(i=1;i<n;i++)
    {

      //  cout<<"stop2";
        if(p[i].second>=x)
        {
          //  cout<<"stop3";
            y++;
            x=p[i].first;
        }
    }
    cout<<y;
    }

}
