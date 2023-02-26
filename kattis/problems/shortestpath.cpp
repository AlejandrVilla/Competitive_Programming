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
int n,m,q,s;

void dijkstra(int org)
{
    pqpii PQ;
    PQ.push({0,org});
    dist[org]=0;
    while(!PQ.empty())
    {
        auto a=PQ.top(); PQ.pop();
        int u,w;
        u=a.second;
        w=a.first;
        if(w>dist[u]) continue;
        for(auto a : adjacent[u])
        {
            int v,d;
            v=a.first;
            d=a.second;
            if(dist[u]+d >= dist[v]) continue;
            dist[v] = dist[u]+d;
            PQ.push({dist[v],v});
        }
    }
}

void solve()
{
    adjacent.resize(n);
    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        adjacent[u].push_back({v,w});
        // adjacent[v].push_back({u,w});
    }
    dist.assign(n,inf);
    dijkstra(s);
    while(q--)
    {
        int v;cin>>v;
        if(dist[v]!=inf)
            cout<<dist[v]<<'\n';
        else
            cout<<"Impossible\n";
    }
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
    while(cin>>n>>m>>q>>s && (n || m || q || s))
    {
        solve();
        cout<<'\n';
    }
}