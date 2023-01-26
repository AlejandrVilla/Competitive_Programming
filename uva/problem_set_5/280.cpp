#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define vs vector<string>
#define pii pair<int,int>
#define qpii queue<pii>
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
using namespace std;

enum{novisitado=0, visitado=1};
vvi adyacencia;
vi visited;
int n;

void dfs(int u, si& alcanzables)
{
    for(auto v : adyacencia[u])
        if(visited[v] == novisitado)
            visited[v] = visitado,
            dfs(v, alcanzables),
            alcanzables.insert(v);
}

void solve()
{
    while(cin>>n && n)
    {
        adyacencia.resize(n);
        int u;
        while(cin>>u && u)
        {
            int v;
            while(cin>>v && v)
                adyacencia[u-1].push_back(v-1);
        }
        int query;cin>>query;
        while(query--)
        {
            int w;cin>>w;
            si alcanzables;
            visited.assign(n,novisitado);
            dfs(w-1, alcanzables);
            cout<<n-alcanzables.size();
            if(alcanzables.size()!=n)
                cout<<' ';
            int c=0;
            for(int i=0 ; i<n ; ++i)
                if(visited[i] == novisitado)
                {
                    cout<<i+1;
                    c++;
                    if(c!=n-alcanzables.size())
                        cout<<' ';
                }
            cout<<'\n';
        }
        adyacencia.clear();
    }
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