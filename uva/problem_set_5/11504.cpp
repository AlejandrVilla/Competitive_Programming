#include <iostream>
#include <stack>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum{visitado=1, novisitado=0, orig=2, trans=3, extr=4};

vvi adjacent, adjacent_t;
vi visited, S;
int n, m, n_SCC=0;
bool SCC_dependent=0;

void dominos(int u, int pass)
{
    visited[u]=visitado;
    vvi& neighbor = (pass==orig)? adjacent : adjacent_t;
    for(auto v:neighbor[u])
    {
        if(visited[v]==novisitado)
            dominos(v,pass);
        else if(visited[v]==extr)
            SCC_dependent=1;
    }
    if(pass=trans)
        visited[u]=extr;
    S.push_back(u);
}

void solve()
{
    cin>>n>>m;
    adjacent.resize(n);
    adjacent_t.resize(n);
    visited.resize(n,novisitado);
    n_SCC=0;
    while(m--)
    {
        int a,b;cin>>a>>b;
        adjacent[a-1].push_back(b-1);
        adjacent_t[b-1].push_back(a-1);
    }
    for(int u=0 ; u<n ; ++u)
        if(visited[u]==novisitado)
            dominos(u,orig);
    visited.assign(n,novisitado);
    for(int u=n-1 ; u>=0 ; --u)
    {
        SCC_dependent=0;
        if(visited[S[u]]==novisitado)
            n_SCC++,dominos(S[u],trans);
        if(SCC_dependent)
            n_SCC--;
    }
    cout<<n_SCC<<'\n';
    adjacent.clear();
    adjacent_t.clear();
    S.clear();
    visited.clear();
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