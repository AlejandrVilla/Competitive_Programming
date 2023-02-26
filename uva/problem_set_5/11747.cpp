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
#define msi multiset<int>
#define MAX 102
using namespace std;

vvpii adjacent;
vtiii edges;
msi res;
int n,m;

vi parent;

void ini()
{
    loop(i,0,n)
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

void Union(int a, int b)
{
    a=par(a);
    b=par(b);
    if(a==b) return;
    parent[b]=a;
}

bool same_set(int a, int b)
{
    a=par(a);
    b=par(b);
    if(a==b) return 1;
    return 0;
}

void kruskal()
{
    sort(edges.begin(),edges.end());
    ini();
    loop(i,0,edges.size())
    {
        int u,v,w;
        w=get<0>(edges[i]);
        u=get<1>(edges[i]);
        v=get<2>(edges[i]);
        if(same_set(u,v)) 
        {
            res.insert(w);
            continue;
        }
        Union(u,v);
    }
}

void solve()
{
    adjacent.resize(n);
    parent.resize(n);
    int u,v,w;
    while(m--)
    {
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    kruskal();
    if(res.size()==0)
        cout<<"forest";
    else
        for(auto it=res.begin() ; it!=res.end() ; ++it)
        {
            cout<<*it;
            if(it!=--res.end())
                cout<<' ';
        }
    cout<<'\n';
    res.clear();
    adjacent.clear();
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
    while(cin>>n>>m && n || m)
        solve();
}