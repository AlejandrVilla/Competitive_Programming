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
#define MAX 1000000
using namespace std;

bitset<MAX+10> criba;
vll primos;
int criba_size;
ll n;

void setCriba(ll N)
{
    criba_size=N+1;
    criba.set();
    criba[0] = criba[1] = 0;
    for(ll i=2 ; i<criba_size ; ++i)
        if(criba[i])
        {
            for(ll j=i*i ; j<criba_size ; j+=i)
                criba[j]=0;
            primos.push_back(i);
        }
}

void solve()
{
    int cont=0;
    ll p1,p2;
    loop(i,0,primos.size())
    {
        p1=primos[i];
        if(p1>n/2) break;
        p2=n-primos[i];
        if(criba[p1] && criba[p2])
            cont++;
    }
    cout<<cont<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // cout<<"asd\n";
    setCriba(MAX);
    while(cin>>n && n)
        solve();
}