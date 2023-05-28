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
#define MAX 10000002
using namespace std;

vi sol(MAX,-1);
int n,m;
bool b=0;

void ini()
{
    for(int i=1 ; i<MAX/3 ; ++i)
        sol[i+2*i] = i;
}

void solve(int i)
{
    if(i==m) { b=1; return;}
    if(i<m) return;
    if(sol[i]==-1) return;
    if(!b) solve(sol[i]);
    if(!b) solve(2*sol[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ini();
    int t;cin>>t;
    while(t--)
    {
        n,m;cin>>n>>m;
        b=0;
        if(n<m)
        {
            cout<<"NO\n";
            continue;
        }
        solve(n);
        if(b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}