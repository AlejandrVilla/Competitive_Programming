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
#define msi multiset<int>
#define MAX 2
using namespace std;

vvi ini(MAX,vi(1,0));
vvi matrix(MAX,vi(MAX,0));
ll n,p;
int MOD;

ll mod(ll a, ll m)
{
    return ((a%m)+m)%m;
}

vvi matrixMul(vvi& A, vvi& B)
{
    vvi C(A.size(),vi(B[0].size(),0));
    loop(i,0,A.size())
        loop(j,0,B[i].size())
            loop(k,0,B.size())
                C[i][j]+=mod(A[i][k]*B[k][j],MOD);
    return C;
}

vvi matrixPow(vvi A, int p)
{
    vvi ans(MAX,vi(MAX,0));
    loop(i,0,MAX) ans[i][i]=1;
    while(p)
    {
        if(p&1)
            ans = matrixMul(ans,A);
        A = matrixMul(A,A);
        p>>=1;
    }
    return ans;
}

void solve()
{
    MOD=1;
    loop(i,0,p)
        MOD<<=1;
    vvi ans = matrixPow(matrix, n);
    ans = matrixMul(ans,ini);
    cout<<ans[1][0]<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ini[0][0]=1;
    ini[1][0]=0;
    matrix[0][0] = matrix[0][1] = matrix[1][0] = 1;
    matrix[1][1] = 0;
    while(cin>>n>>p)
        solve();
}