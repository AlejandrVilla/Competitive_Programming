#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define MAX 1000
using namespace std;

enum{visitado=0, novisitado=1, nada=2};
vi visited(2*MAX,nada);
vvi adyacencia(2*MAX);

void dfs(int u)
{
    visited[u] = visitado;
    for(auto v : adyacencia[u])
        if(visited[v] == novisitado)
            dfs(v);
}

void solve()
{
    int n;cin>>n;
    while(n--)
    {
        int x,y;cin>>x>>y;
        adyacencia[x-1].push_back(y+MAX-1);
        adyacencia[y+MAX-1].push_back(x-1);
        visited[x-1]=novisitado;
        visited[y+MAX-1]=novisitado;
    }
    int ncc=0;
    for(int u=0 ; u<2*MAX ; ++u)
        if(visited[u] == novisitado)
            dfs(u), ncc++;
    cout<<ncc-1<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}