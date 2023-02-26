#include <iostream>
#include <math.h>
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
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vd vector<double>
#define vvi vector<vi>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define msi multiset<int>
#define MAX 1002
using namespace std;

vtdii edges;                    // aristas -> peso, v1, v2
vi parent(MAX);
vvd vertex(MAX,vd(2,0));        // n vertices con coordenadas x, y
int n,s;
double roads,railroads;
int n_states;

void ini()
{
    loop(i,0,n)
        parent[i]=i;
}

int par(int a)
{
    while(a != parent[a])
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
    int k=0;
    for(int i=0 ; k!=n-1 ; ++i)
    {
        int u,v;
        double w;
        w=get<0>(edges[i]);
        u=get<1>(edges[i]);
        v=get<2>(edges[i]);
        if(same_set(u,v))continue;
        Union(u,v);
        if(w<=s)              
            roads+=w;
        else         // si w>s añade arista que conecta dos estados diferentes
        {
            railroads+=w;
            n_states++;
        }
        k++;
    }
}   

void solve()
{
    cin>>n>>s;
    // para cada vertice
    loop(i,0,n)                     
    {   
        cin>>vertex[i][0];          // guarda x
        cin>>vertex[i][1];          // guarda y
    }
    // todas las posibles aristas (grafo full conexo)
    loop(i,0,n)                 // vertice i con
        loop(j,i+1,n)           // vertice j
        {
            double w = sqrt(pow(vertex[i][0]-vertex[j][0],2)+pow(vertex[i][1]-vertex[j][1],2));
            edges.push_back({w,i,j});
        }
    roads=railroads=0;
    n_states=1;
    kruskal();
    // lround, redondear entero mas cercano
    cout<<n_states<<" "<<lround(roads)<<" "<<lround(railroads);  
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
    int i=1,t;cin>>t;
    while(t--)
    {
        cout<<"Case #"<<i++<<": ";
        solve();
        cout<<'\n';
    }
}