#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum{visitado=0, novisitado=1};
vvi adjacencia;
vi visited;
int n,t;
bool c;

void dfs(int u)
{
    if(u==t-1)
    {
        c=1;
        return;
    }
    visited[u] = visitado;
    for(auto v:adjacencia[u])
        if(visited[v] == novisitado)
            dfs(v);
}

void solve()
{
    cin>>n>>t;
    adjacencia.resize(n);
    visited.assign(n,novisitado);
    c=0;
    for(int i=0 ; i<n-1 ; ++i)
    {
        int num; cin>>num;
        adjacencia[i].push_back(i+num);
    }
    dfs(0);
    if(c)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
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