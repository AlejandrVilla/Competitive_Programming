#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
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
using namespace std;

int n,m,k;
vvpii adjacent;
vvpii MST;
vtiii edges;
int min_cost, new_min_cost;
int num_taken;
vi parent;

void ini()
{
    
    int i;
    loop(i,0,n)
    //for(int i=0 ; i<n ; ++i)
        parent[i]=i;
}

int par(int a)
{
    while(a!=parent[a])
    {
        parent[a]=parent[parent[a]];
        a=parent[a];
    }
    return a;
}

void Union(int a,int b)
{
    a = par(a);
    b = par(b);
    if(a==b) return;
    parent[b]=a;
}

bool same_set(int a, int b)
{
    a = par(a);
    b = par(b);
    if(a==b) return 1;
    return 0;
}

void kruskal()
{
    sort(edges.begin(), edges.end());
    ini();
    for(int i=0 ; num_taken!=n-1 ; ++i)
    {
        int w=get<0>(edges[i]);
        int u=get<1>(edges[i]);
        int v=get<2>(edges[i]);
        if(same_set(u,v)) continue;
        new_min_cost+=w;
        num_taken++;
        Union(u,v);
        //MST[u].push_back({v,w});
        //MST[v].push_back({u,w});
    }
}

void solve()
{
    //adjacent.resize(n);
    parent.resize(n);
    //MST.resize(n);
    int u,v,w;
    num_taken = min_cost = new_min_cost = 0;
    int i;
    loop(i,0,n-1)
    {
        cin>>u>>v>>w;
        min_cost+=w;
    }
    cin>>k;
    while(k--)
    {
        cin>>u>>v>>w;
        edges.push_back({w,u-1,v-1});
    }
    cin>>m;
    while(m--)
    {
        cin>>u>>v>>w;
        edges.push_back({w,u-1,v-1});
    }
    kruskal();
    cout<<min_cost<<'\n';
    cout<<new_min_cost<<'\n';
    edges.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=0;
    while(cin>>n)
    {   
        if(i!=0)
            cout<<'\n';
        solve();
        i++;
    }
}