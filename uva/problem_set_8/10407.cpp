/*
    arr = {a=n*k+r, b=m*k+r, c=p*k+r, ...}
    desde arr[1] hasta arr[n-1] resto arr[0]
    -> para arr[1] - arr[0] = m*k+r - (n*k+r)
                            = m*k - n*k 
                            = k*(m-n) 
    -> para arr[2] - arr[0] = k*(p-n)
    -> lo mismo para cada elemento en arr, 
       despues de la resta, todos seran multiplos de k
       entonces respuesta es gcd(arr[1], arr[2], ... arr[n-1]) = k
*/

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

vi arr;
int num;

void solve()
{   
    arr.push_back(num);
    while(cin>>num && num)
        arr.push_back(num);
    loop(i,1,arr.size())
        arr[i]-=arr[0];
    int g=arr[1];
    loop(i,2,arr.size())
        g=__gcd(g,arr[i]);
    cout<<abs(g)<<'\n';
    arr.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>num && num)
        solve();
}