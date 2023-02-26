#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define ll long long int
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define MAX 102
using namespace std;

enum{inf=INT32_MAX};
vvll adjacent;
si vertices;
int u,v;
int n;
int n_v;

void floyd_Warshal()
{
    loop(k,0,n)
        loop(i,0,n)
            loop(j,0,n)
                adjacent[i][j]=min(adjacent[i][j],adjacent[i][k]+adjacent[k][j]);
}

void solve()
{
    adjacent.assign(MAX,vll(MAX,inf));
    n=0;
    n=max(n,max(u,v));
    vertices.insert(u);
    vertices.insert(v);
    adjacent[u-1][v-1]=1;
    while(cin>>u>>v && (u||v))
    {
        adjacent[u-1][v-1]=1;
        n=max(n,max(u,v));
        vertices.insert(u);
        vertices.insert(v);
    }
    n_v=vertices.size();
    loop(i,0,n)
        adjacent[i][i]=0;
    floyd_Warshal();
    double total=n_v*(n_v-1);
    double cont=0;
    loop(i,0,n)
        loop(j,0,n)
            if(adjacent[i][j]!=INT32_MAX)
                cont+=adjacent[i][j];
    // cout<<total<<" "<<cont<<'\n';
    cout<<cont/total;
    vertices.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=1;
    while(cin>>u>>v && (u || v))
    {
        cout<<"Case "<<setprecision(3)<<fixed<<i++<<": average length between pages = ";
        solve();
        cout<<" clicks\n";
    }
}