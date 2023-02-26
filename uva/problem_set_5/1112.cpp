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
int N,M,T,E;
int sol;

// dijkstra
vvpii adjacent;
vi dist;

// floyd warshall
vvi MA;     

void floyd_warshall()
{
    loop(k,0,N)
        loop(i,0,N)
            loop(j,0,N)
                MA[i][j]=min(MA[i][j],MA[i][k]+MA[k][j]);
}

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
        for(auto e : adjacent[u])
        {
            int v,d;
            v=e.first;
            d=e.second;
            if(dist[u]+d >= dist[v]) continue;
            dist[v]=dist[u]+d;
            PQ.push({dist[v],v});
        }
    }
}

void solve()
{
    cin>>N>>E>>T>>M;
    adjacent.resize(N);
    int u,v,w;
    while(M--)
    {
        cin>>u>>v>>w;
        adjacent[v-1].push_back({u-1,w});
    }
    sol=0;
    dist.assign(N,inf);
    dijkstra(E-1);
    loop(i,0,N)
        if(dist[i]<=T)
            sol++;
    cout<<sol<<'\n';
    adjacent.clear();
}

void solve2()
{
    cin>>N>>E>>T>>M;
    MA.assign(N,vi(N,inf/2));
    loop(i,0,N)
        MA[i][i]=0;
    int u,v,w;
    while(M--)
    {
        cin>>u>>v>>w;
        MA[u-1][v-1]=w;
    }   
    floyd_warshall();
    sol=0;
    loop(i,0,N)
        if(MA[i][E-1]<=T)
            sol++;
    cout<<sol<<'\n';    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
    {
        solve2();
        if(t!=0) cout<<'\n';
    }
}