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

bitset<MAX+10> bs;
vll primos;
ll n,criba_size;

void criba(ll N)
{
    criba_size=N+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2 ; i<criba_size ; ++i)
    {
        if(bs[i])
        {
            for(ll j=i*i ; j<criba_size ; j+=i)
                bs[j]=0;
            primos.push_back(i);
        }
    }
}

// void solve()
// {
//     ll maximo=-1;
//     ll p1=0,p2=0;
//     loop(i,0,primos.size())
//     {
//         if(primos[i]>n) break;
//         if(bs[n-primos[i]])
//             if(abs(primos[i]-(n-primos[i])) >= maximo)
//             {
//                 maximo = abs(primos[i]-(n-primos[i]));
//                 p1 = primos[i];
//                 p2 = n-primos[i];
//             }
//     }
//     cout<<n<<" = "<<min(p1,p2)<<" + "<<max(p1,p2)<<'\n';
// }

void solve()
{
    int p1,p2;
    loop(i,0,primos.size())
    {
        p1=primos[i];
        p2=n-p1;
        if(bs[p2])
        {
            cout<<n<<" = "<<p1<<" + "<<p2<<"\n";
            return;
        }
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
    criba(MAX);
    while(cin>>n && n)
        solve();
}