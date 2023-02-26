#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <sstream>
#include <fstream>
#define loop(a,b,c) for(a=b;a<c;++a)
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
using namespace std;

vvpii adjacent;
pqpii pq;
vi taken;
int min_cost, num_taken, total_cost;
int n,m;

void process(int u)
{
    taken[u]=1;
    for(auto v : adjacent[u])
        if(!taken[v.first])
            pq.push({v.second,v.first});    // peso, vertice
}


void prim()
{
    process(0);
    while(!pq.empty() && num_taken!=n-1)
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(taken[v]) continue;
        min_cost+=w;
        process(v);
        num_taken++;
    }
}

void solve()
{
    adjacent.resize(n);
    taken.assign(n,0);
    num_taken=min_cost=total_cost=0;
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        adjacent[u].push_back({v,w});
        adjacent[v].push_back({u,w});
        total_cost+=w;
    }
    prim();
    cout<<total_cost-min_cost<<'\n';
    adjacent.clear();
    while(!pq.empty()) pq.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m && (n || m))
        solve();
}