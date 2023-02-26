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
#define sll set<ll>
#define msi multiset<int>
#define MAX 100000000
using namespace std;

ll n;
bitset<MAX+2> criba;
vll primos;
ll criba_size;

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
    ll p1,p2;
    if(n==1 || n==2 || n==3 || n==4)
    {
        cout<<n<<" is not the sum of two primes!\n";
        return;
    }
    else if(n%2!=0 && criba[n-2])
    {
        cout<<n<<" is the sum of "<<2<<" and "<<n-2<<".\n";
        return;
    }
    else if(n%2==0)
    {
        auto it = upper_bound(primos.begin(), primos.end(),n/2);
        for( ; it!=primos.end() ; ++it)
        {
            p1 = *it;
            if(p1>n) break;
            p2 = n-p1;
            if(criba[p2])
            {
                cout<<n<<" is the sum of "<<p2<<" and "<<p1<<".\n";
                return;
            }
        }
    }
    cout<<n<<" is not the sum of two primes!\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    setCriba(MAX);
    while(cin>>n)
        solve();
}