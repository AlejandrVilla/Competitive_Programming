#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define mii map<int,int>
using namespace std;

enum{novisitado=0, visitado=1};
vvi adjacencia;
vi visited;
int n,m;

void dfs(int u)
{
    visited[u] = visitado;
    for(auto v : adjacencia[u])
        if(visited[v]==novisitado)
            dfs(v);
}

void solve()
{
    cin>>n>>m;
    adjacencia.resize(n);
    visited.assign(n,novisitado);
    while(m--)
    {
        int u,v;cin>>u>>v;
        adjacencia[u].push_back(v);
        adjacencia[v].push_back(u);
    }
    int cc=0;
    for(int i=0 ; i<n ; ++i)
        if(visited[i]==novisitado)
            cc++,dfs(i);
    cout<<cc-1<<'\n';
    adjacencia.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    /*
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif*/
    int t;cin>>t;
    while(t--)
        solve();
}