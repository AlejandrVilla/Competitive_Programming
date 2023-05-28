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
#define MAX 22
using namespace std;

void solve()
{
    int n;cin>>n;
    mmistr res;
    mmistr res2;
    while(n--)
    {
        int a;
        string s;
        cin>>a>>s;
        if(s=="11")
            res2.insert({a,s});
        else if(s!="00")
            res.insert({a,s});
    }
    int c1=(res2.size()>0)? res2.begin()->first : 0;
    int c=0;
    bool b1=0,b2=0;
    for(auto it=res.begin() ; it!=res.end() ; ++it)
    {
        if(it->second=="10" && !b1)
        {
            c+=it->first;
            b1=1;
        }
        else if(it->second=="01" && !b2)
        {
            c+=it->first;
            b2=1;
        } 
    }
    if(c1 && b1 && b2)
    {
        c=min(c,c1);
        cout<<c<<'\n';
    }
    else if(c1)
        cout<<c1<<'\n';
    else if(b1 && b2)
        cout<<c<<'\n';
    else    cout<<-1<<'\n';
    
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