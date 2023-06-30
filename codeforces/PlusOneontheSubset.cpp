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
#define TEST(a,i) ((a) & (1<<(i)))      //comprueba si el i-esimo bit esta activado
#define SET(a,i) ((a) | (1<<(i)))       //activa el i-esimo bit
#define CLEAR(a,i) ((a) & ~(1<<(i)))    //desactiva el i-esimo bit
#define FLIP(a,i) ((a) ^ (1<<(i)))      //invertir el estado del i-esimo bit
#define LSO(n) ((n) & (-n))             //primer bit por la derecha
#define isPow(n) (((n) & (n)-1) == 0 && (n)) //potencia de 2
#define submask(a,b) ((a) & (b) == b)       //submascara
#define supmasl(a,b) ((a) | (b) == b)       //supermascara
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
    int n;cin>>n;
    vi arr(n);
    loop(i,0,n)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    cout<<arr[n-1]-arr[0]<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
        solve();
}