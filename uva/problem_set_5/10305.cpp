#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

using namespace std;
enum{novisitado=0,visitado=1};
int n,m;
vvi adjacencia;
vi visited;
vi tposort;

void dfs(int u)
{
    visited[u] = visitado;
    for(auto v : adjacencia[u])
    {
        if(visited[v]==novisitado)
            dfs(v);
    }
    tposort.push_back(u);
}

void solve()
{
    adjacencia.resize(n);
    visited.assign(n,novisitado);
    while(m--)
    {
        int u,v;cin>>u>>v;
        adjacencia[u-1].push_back(v-1);
    }
    for(int i=0 ; i<n ; ++i)
        if(visited[i]==novisitado)
            dfs(i);
    for(int i=n-1 ; i>=0 ; i--)
    {
        cout<<tposort[i]+1;
        if(i!=0)
            cout<<' ';
    }
    cout<<'\n';
    adjacencia.clear();
    tposort.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m && (n || m ))
        solve();
}