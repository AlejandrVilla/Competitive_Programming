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
#define vd vector<double>
#define vvi vector<vi>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define msi multiset<int>
#define MAX 10000010
using namespace std;

vll primos;
bitset<MAX> bs;
ll criba_size;
ll L,U;

void criba(ll n)                
{
    criba_size = n+1;
    bs.set();               
    bs[0] = bs[1] = 0;      
    for(ll i=2 ; i<criba_size ; ++i)
    {
        if(bs[i])                       
        {
            for(ll j=i*i ; j<criba_size ; j+=i)
                bs[j] = 0;              
            primos.push_back(i);
        }
    }
}

bool isPrime(ll n)             
{
    if(n<criba_size) return bs[n];     
    for(int i=0 ; i<primos.size() && primos[i]*primos[i]<=n ; ++i)      
        if(n%primos[i]==0)              
            return false;
    return true;                
}

void solve()
{
    vll res;
    // cout<<L<<" "<<U<<'\n';
    for(ll a=L ; a<=U ; ++a)
    {
        if(isPrime(a))
            res.push_back(a);
    }
    if(res.size()<=1)
        cout<<"There are no adjacent primes.\n";
    else
    {
        ll max_dist=0;
        ll min_dist=INT64_MAX;
        ll a,b,c,d;
        for(int i=0 ; i<res.size()-1 ; ++i)
        {
            if(res[i+1]-res[i] > max_dist)
            {
                max_dist = res[i+1]-res[i];
                a=res[i+1];
                b=res[i];
            }
            if(res[i+1]-res[i] < min_dist)
            {
                min_dist = res[i+1]-res[i];
                c=res[i+1];
                d=res[i];
            }
        }
        //2,3 are closest, 7,11 are most distant.
        cout<<d<<","<<c<<" are closest, "<<b<<","<<a<<" are most distant.\n";
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
    int n=MAX;
    criba(n);
    while(cin>>L>>U)
        solve();
}