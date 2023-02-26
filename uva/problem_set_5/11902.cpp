#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define MAX 100
using namespace std;

enum{invalido=0, valido=1, novisitado=2, visitado=3, alcanzable=4, noalcanzable=5};
vvi adjacent;
vi visited;
vi valid;
vi alcan;
vvi sol;
int n;

void bfs(int u)
{
    qi Q;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        visited[u]=visitado;
        alcan[u]=alcanzable;
        for(auto v : adjacent[u])
            if(visited[v]==novisitado)
                Q.push(v);
    }
}

bool bfs(int u, int k)
{
    qi Q;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        visited[u]=visitado;
        if(u==k) return 1;
        for(auto v : adjacent[u])
            if(valid[v]==valido && visited[v]==novisitado)
                Q.push(v);
    }
    return 0;
}

void solve()
{
    cin>>n;
    adjacent.resize(n);
    valid.assign(n,valido);
    visited.assign(n,novisitado);
    alcan.assign(n,noalcanzable);
    sol.assign(n,vi(n,0));
    int num;
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<n ; ++j)
        {
            cin>>num;
            if(num) adjacent[i].push_back(j);
        }
    bfs(0);
    visited.assign(n,novisitado);
    loop(u,0,n)
    {
        if(alcan[u]==noalcanzable) continue;
        valid[u]=invalido;
        sol[u][u]=1;
        sol[0][u]=1;
        loop(v,0,n)
        {
            if(alcan[v]==noalcanzable) continue;
            if(!bfs(0,v)) sol[u][v]=1;
            visited.assign(n,novisitado);
        }
        valid[u]=valido;
    }
    string line(2*n+1,'-');
    line[0]=line[2*n]='+';
    cout<<line+'\n';
    loop(i,0,n)
    {
        cout<<'|';
        loop(j,0,n)
        {
            if(sol[i][j]) cout<<"Y|";
            else cout<<"N|";
        }
        cout<<'\n'+line+'\n';
    }
    adjacent.clear();
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
    int i=1;
    while(t--)
    {
        cout<<"Case "<<i++<<":\n";
        solve();
    }
}