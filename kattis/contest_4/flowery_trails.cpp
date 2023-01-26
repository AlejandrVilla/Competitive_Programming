/*uva 12878*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define vi vector<int>
#define ll long long int
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define pqpii priority_queue<pii,vpii,greater<pii>>
using namespace std;

enum{inf=INT_MAX};
vvi adjacent;             
vi dist1, dist2;
vvi rep;
pqpii pq;
int n,m;

void dijkstra(int org, int fin, vi& dist)
{
    dist[org]=0;
    pq.push({0,org});
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(w > dist[u]) continue;
        for(int v=0 ; v<n ; ++v)
        {
            if(adjacent[u][v])
            {
                int d=adjacent[u][v];
                if(dist[u]+d >= dist[v]) continue;
                dist[v]=dist[u]+d;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve()
{
    while(cin>>n>>m)
    {
        adjacent.assign(n,vi(n,0));
        rep.assign(n,vi(n,0));
        dist1.assign(n,inf);
        dist2.assign(n,inf);
        while(m--)
        {
            int u,v,w;cin>>u>>v>>w;
            if(u==v) continue;
            if(adjacent[u][v])
            {
                if(w<adjacent[u][v])
                {
                    adjacent[u][v]=w;
                    adjacent[v][u]=w;
                    rep[u][v]=0;
                }
                else if(w==adjacent[u][v])
                    rep[u][v]+=w;
            }
            else
            {
                adjacent[u][v]=w;
                adjacent[v][u]=w;
            }
        }
        dijkstra(0,n-1,dist1);
        dijkstra(n-1,0,dist2);
        int min_d=dist1[n-1];
        int ac=0;
        for(int i=0 ; i<n ; ++i)
            for(int j=0 ; j<n ; ++j)
                if(dist1[i] + adjacent[i][j] + dist2[j] == min_d)
                    ac+=adjacent[i][j]+rep[i][j];
        cout<<2*ac<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}