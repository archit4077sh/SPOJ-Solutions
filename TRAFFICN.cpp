#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<long long,long long>,vector<pair<long long, long long> >,greater<pair<long long ,long long> > >pq,pq1;
vector<vector< pair<long long,long long> > >vec,rev;
vector<long long>dist;
vector<long long>visited;
vector<long long>revdist;
vector<long long>revvisited;
void relax(long long u,long long v,long long w)
{
    if(dist[v]>dist[u]+w)
    {
        dist[v]=dist[u]+w;
        pq.push({dist[v],v});
    }
}
void revrelax(long long u,long long v,long long w)
{
    if(revdist[v]>revdist[u]+w)
    {
        revdist[v]=revdist[u]+w;
        pq1.push({revdist[v],v});
    }
}

void dijkstra()
{
    while(!pq.empty())
    {
    long long src=pq.top().second;
    pq.pop();
    if(!visited[src])
    {
    for(long long i=0;i<vec[src].size();i++)
        if(!visited[vec[src][i].second])
        relax(src,vec[src][i].second,vec[src][i].first);
    visited[src]=1;
    }
    }
}
void revdijkstra()
{
    while(!pq1.empty())
    {
    long long src=pq1.top().second;
    pq1.pop();
    if(!revvisited[src])
    {
    for(long long i=0;i<rev[src].size();i++)
        if(!revvisited[rev[src][i].second])
        revrelax(src,rev[src][i].second,rev[src][i].first);
    revvisited[src]=1;
    }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin>>t;
    while(t--)
    {
    vec.clear();
    rev.clear();
    dist.clear();
    revdist.clear();
    visited.clear();
    revvisited.clear();
    long long n,m,k,s,t,i;
    cin>>n>>m>>k>>s>>t;
    long long arr[k+1][4];
    vec.resize(n+1);
    rev.resize(n+1);
    dist.resize(n+1);
    revdist.resize(n+1);
    visited.resize(n+1);
    revvisited.resize(n+1);
    for(i=1;i<n+1;i++)
        {
            dist[i]=1061109567;
            revdist[i]=1061109567;
            visited[i]=0;
            revvisited[i]=0;
        }
    dist[s]=0;
    revdist[t]=0;
    for(i=0;i<m;i++)
    {
        long long di,ci,li;
        cin>>di>>ci>>li;
        vec[di].push_back({li,ci});
        rev[ci].push_back({li,di});
    }
    pq.push({dist[s],s});
    pq1.push({0,t});
    dijkstra();
    revdijkstra();
    for(i=1;i<=k;i++)
         cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
    long long mini=min(dist[t],revdist[s]);
    for(i=1;i<=k;i++)
    {
        long long u=arr[i][1],v=arr[i][2],w=arr[i][3];
        mini=min(mini,min(dist[u]+w+revdist[v],dist[v]+revdist[u]+w));
    }
    if(dist[t]==1061109567)
        cout<<"-1\n";
    else
        cout<<mini<<"\n";
    }
}
