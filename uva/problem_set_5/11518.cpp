#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;
enum{caido=0, nocaido=1};

vvi adjacent;
vi knocked;
int n,m,l;
int res;

void dominoes(int u)
{
    knocked[u]=caido;
    for(auto v:adjacent[u])
        if(knocked[v]==nocaido)
        {
            res++;
            dominoes(v);
        }
}

void solve()
{
    cin>>n>>m>>l;
    adjacent.resize(n);
    knocked.resize(n,nocaido);
    res=0;
    while(m--)
    {
        int u,v;cin>>u>>v;
        adjacent[u-1].push_back(v-1);
    }
    while(l--)
    {
        int u;cin>>u;
        if(knocked[u-1]==nocaido)
        {
            res++;
            dominoes(u-1);
        }
    }
    adjacent.clear();
    knocked.clear();
    cout<<res<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
        solve();
}