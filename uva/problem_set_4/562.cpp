#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b;a<c;++a)
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define MAX 100
using namespace std;

// mimii mem;       // con map demora mucho
vvi mem;
vi p(MAX+1);
int n;

bool existe(int f, int c)
{
    if(mem[f][c]) return 1;
    // if(mem[f].count(c)) return 1;
    return 0;
}

int mochila(int indx, int W)
{
    if(indx == n) return 0;
    if( existe(indx,W) ) return mem[indx][W];
    int ganancia1=0;
    if(p[indx] <= W)
        ganancia1 = p[indx] + mochila(indx+1, W-p[indx]);
    int ganancia2 = mochila(indx+1, W);
    mem[indx][W] = max(ganancia1, ganancia2);
    return mem[indx][W];
}

void solve()
{
    cin>>n;
    int sum = 0;
    loop(i,0,n)
    {
        cin>>p[i];
        sum+=p[i];
    }
    mem.assign(n,vi(sum+1));
    int optimo = mochila(0,sum/2);
    int tmp=sum-optimo;
    cout<<abs(optimo-tmp)<<'\n';
    mem.clear();
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