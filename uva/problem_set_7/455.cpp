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
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define uomstri unordered_map<string,int>
#define mii map<int,int>
#define si set<int>
#define sc set<char>
#define sll set<ll>
#define msi multiset<int>
#define MAX 100000000
using namespace std;

int n;
string str;

void solve()
{
    vi res;
    cin>>str;
    loop(i,1,str.size()+1)
    {
        loop(j,0,str.size()-i+1)
        {
            string aux;
            string tmp=str.substr(j,i);
            // cout<<tmp<<'\n';
            int n=ceil(double(str.size())/double(i));
            loop(k,0,n)
                aux+=tmp;
            // cout<<aux<<'\n';
            if(aux==str)
            {
                cout<<i<<'\n';
                return;
            }
        }
    }
    // cout<<res[0]<<"\n";
}   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n;
    int i=1;
    while(n--)
    {
        solve();
        if(n!=0)
            cout<<'\n';
    }
}