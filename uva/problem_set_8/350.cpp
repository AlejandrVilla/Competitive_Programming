#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
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
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define msi multiset<int>
#define MAX 10000000
using namespace std;

int Z,I,M,L;

int mod(int a, int m)
{
    return ((a%m)+m)%m; 
}

int f(int x)
{
    return mod((Z*x+I),M);
}

pii floydCycleFind(int x0)
{
    int t=f(x0), h=f(f(x0));
    while(t!=h) {t=f(t); h=f(f(h));}

    int mu=0; h=x0;
    while(t!=h) {t=f(t); h=f(h); ++mu;}

    int lambda=1; h=f(t);
    while(t!=h) {h=f(h); ++lambda;}

    return {mu,lambda};
}

void solve()
{
    cout<<floydCycleFind(L).second;
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
    while(cin>>Z>>I>>M>>L && (Z || I || M || L))
    {
        cout<<"Case "<<i++<<": ";
        solve();
        cout<<'\n';
    }
}