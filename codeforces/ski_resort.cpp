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

void solve()
{   
    long long int n,k,q;cin>>n>>k>>q;
    vll a(n);
    for(int i=0 ; i<n ; ++i)
        cin>>a[i];
    long long int ans=0;
    long long int l=0;
    for(int i=0 ; i<n ; ++i)
    {
        if(a[i]<=q)
            l++;
        else
        {
            if(l>=k)
                ans+=(l-k+1)*(l-k+2)/2;
            l=0;
        }
    }
    if(l>=k)
        ans+=(l-k+1)*(l-k+2)/2;
    cout<<ans<<'\n';
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
