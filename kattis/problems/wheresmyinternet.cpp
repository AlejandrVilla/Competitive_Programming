#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define mii map<int,int>
using namespace std;

enum{noconected=0, conected=1};
vvi adjacencia;
vi red;
int n,m;
int k=0;

void dfs(int u)
{
    k++;
    red[u] = conected;
    for(auto v : adjacencia[u])
        if(red[v]==noconected)
            dfs(v);
}

void solve()
{
    cin>>n>>m;
    adjacencia.resize(n);
    red.assign(n,noconected);
    while(m--)
    {
        int u,v;cin>>u>>v;
        adjacencia[u-1].push_back(v-1);
        adjacencia[v-1].push_back(u-1);
    }
    dfs(0);
    if(k==n)
        cout<<"Connected\n";
    else
        for(int u=0 ; u<n ; ++u)
            if(red[u]==noconected)
                cout<<u+1<<'\n';
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
    solve();
}