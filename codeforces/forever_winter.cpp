#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define vstr vector<string>
#define ll long long int
#define tiii tuple<int,int,int>
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vbl vector<bool>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define uomstri unordered_map<string,int>
#define mii map<int,int>
#define mistr map<int,string>
#define mmistr multimap<int,string>
#define miqi map<int,qi>
#define mmii multimap<int,int>
#define si set<int>
#define sc set<char>
#define sstr set<string>
#define sll set<ll>
#define vsi vector<si>
#define uomisi unordered_map<int,si>
#define msi multiset<int>
#define MAX 1002
using namespace std;

enum{visitado=0, novisitado=1};

vvi adjacent;
vi visit;
int n,m;
mii res;        // grado, cantidad

/*
    grado | cantidad
        1   xy
        y+1   x
        x   1
    y = x+1
    grado | cantidad
        1      xy
        x=y+1  x+1

    ################# 
    cantidad | grado
        1       x
        x       y+1
        xy      1

    y = x+1
    cantidad | grado
        x+1     x=y+1
        xy      1
*/

void bfs(int org)
{
    qi Q;
    visit[org]=visitado;
    Q.push(org);
    while(!Q.empty())
    {
        int u=Q.front(); Q.pop();
        int c=0;
        for(auto v : adjacent[u])
        {
            c++;
            if(visit[v]==novisitado)
            {
                Q.push(v);
                visit[v]=visitado;
            }
        }
        res[c]++;
    }
}

void solve()
{
    cin>>n>>m;
    adjacent.resize(n+1);
    visit.assign(n+1,novisitado);
    while(m--)
    {
        int u,v;cin>>u>>v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
    bfs(1);
    // for(int i=1 ; i<n+1 ; ++i)
    //     res[adjacent[i].size()]++;       // sin dfs, tambien solucion
    int x,y,xy;
    if(res.size()==2)
    {
        xy=res.begin()->second;
        x=((++res.begin())->second)-1;
        y=xy/x;
    }
    else
    {
        xy=res.begin()->second;
        for(auto a : res)
            if(a.second==1)
                x=a.first;
        y=xy/x;
    }
    cout<<x<<" "<<y<<'\n';
    res.clear();
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
    while(t--)
        solve();
}