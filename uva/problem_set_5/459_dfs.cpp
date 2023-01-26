#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum{visitado=0, novisitado=1};
vvi adjacencia;
vi visited;

void dfs(int u)
{
    visited[u] = visitado;
    for(auto v : adjacencia[u])
        if(visited[v] == novisitado)
            dfs(v);
}

void solve()
{
    char u;cin>>u;
    int n=int(u-'A')+1;
    adjacencia.resize(n);
    visited.assign(n,novisitado);
    cin.ignore();
    string edge;
    while(getline(cin,edge) && edge!="")
    {
        adjacencia[int(edge[0]-'A')].push_back(int(edge[1]-'A'));
        adjacencia[int(edge[1]-'A')].push_back(int(edge[0]-'A'));
    }
    int ncc=0;
    for(int u=0 ; u<n ; ++u)
        if(visited[u]==novisitado)
            dfs(u),ncc++;
    cout<<ncc<<'\n';
    adjacencia.clear();
    visited.clear();
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
        solve();
        if(t!=0)
            cout<<'\n';
    }
}