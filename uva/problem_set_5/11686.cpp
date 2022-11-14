#include <iostream>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum {visitado=0, novisitado=1, explorado=2};

vvi adjacent;
vi visited;
vi res;
int n,m;
bool ac=0;

void sticks(int u)
{
    visited[u] = explorado;
    for(auto v:adjacent[u])
    {
        if(visited[v]==novisitado)
            sticks(v);
        else if(visited[v]==explorado)
        {
            ac=1;
            return;
        }
    }
    res.push_back(u);
    visited[u]=visitado;
}

void solve()
{
    while(cin>>n>>m && (n||m))
    {
        adjacent.clear();
        visited.clear();
        res.clear();
        adjacent.resize(n);
        visited.resize(n,novisitado);
        ac=0;
        while(m--)
        {
            int a,b;cin>>a>>b;
            adjacent[a-1].push_back(b-1);
        }
        for(int u=0 ; u<n && !ac ; ++u)
            if(visited[u]==novisitado)
                sticks(u);
        if(ac)
            cout<<"IMPOSSIBLE\n";
        else
            for(int i=n-1 ; i>=0 ; --i)
                cout<<res[i]+1<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}