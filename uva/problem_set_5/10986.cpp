#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define ll long long int
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define MAX 102
using namespace std;

enum{inf=INT32_MAX};
vvpii adjacent;
vi dist;
int n,m,s,t;

void dijkstra(int org)
{
    pqpii PQ;
    dist[org]=0;
    PQ.push({0,org});
    while(!PQ.empty())
    {
        auto e=PQ.top(); PQ.pop();
        int u=e.second;
        int w=e.first;
        if(w>dist[u]) continue;
        for(auto a : adjacent[u])
        {
            int v=a.first;
            int d=a.second;
            if(dist[v]<=dist[u]+d) continue;
            dist[v]=dist[u]+d;
            PQ.push({dist[v],v});
        }
    }
}

void solve()
{
    cin>>n>>m>>s>>t;
    adjacent.resize(n);
    dist.assign(n,inf);
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        adjacent[u].push_back({v,w});
        adjacent[v].push_back({u,w});
    }
    dijkstra(s);
    if(dist[t]==inf)
        cout<<"unreachable\n";
    else
        cout<<dist[t]<<'\n';
    adjacent.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=1;
    int t;cin>>t;
    while(t--)
    {
        cout<<"Case #"<<i++<<": ";
        solve();
    }
}