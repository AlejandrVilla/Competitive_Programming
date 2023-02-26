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
#define MAX 1000000
using namespace std;

char str[MAX];
bool ini_q=1;

void solve()
{
    int i=0,j=0;
    while(str[i]!='\0')
    {
        if(str[i]=='\"' && ini_q)
        {
            putchar('`');
            putchar('`');
            ini_q=0;
        }
        else if(str[i]=='\"' && !ini_q)
        {
            putchar('\'');
            putchar('\'');
            ini_q=1;
        }
        else
            putchar(str[i]);
        ++i;
    }
    puts("");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(gets(str))
        solve();
}