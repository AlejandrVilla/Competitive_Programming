#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define MAX_N 2
using namespace std;

vvi matrix(MAX_N,vi(MAX_N,0));
vvi ini(MAX_N,vi(1,0));

ll mod(ll a, ll m)
{
    return ((a%m)+m)%m;     // modulo siempre positivo
}

vvi matMul(vvi& A, vvi& B)
{
    vvi ans(A.size(),vi(B[0].size(),0));        // (mxn),(nxp)
    for(int i=0 ; i<A.size() ; ++i)             // m
        for(int j=0 ; j<B.size() ; ++j)         // n
            for(int k=0 ; k<B.size() ; ++k)     // n
                ans[i][j] += mod(A[i][k]*B[k][j],10000);
    return ans;
}

vvi matrixPow(vvi base, int p)
{
    vvi ans(MAX_N,vi(MAX_N,0));
    for(int i=0 ; i<MAX_N ; ++i)
        ans[i][i] = 1;
    while(p)
    {
        if(p&1)     // impar
            ans = matMul(ans, base);        // ultima potencia impar
        base = matMul(base, base);          // DV, base^k * base^k
        p>>=1;      // p/2
    }
    return ans;
}

void lastDigits(ll num, int k)
{
    string _num = to_string(num);
    string res;
    for(int i=0 ; i<k && i<_num.size(); ++i)
        res.push_back(_num[_num.size()-i-1]);
    int i=res.size()-1;
    while(res[i--]=='0')
        res.pop_back();
    reverse(res.begin(), res.end());
    if(res.size()==0)
        cout<<"0\n";
    else
        cout<<res<<'\n';
}

void solve()
{
    ll a,b,n,m;cin>>a>>b>>n>>m;
    ini[0][0] = b, ini[1][0] = a;
    if(n==0)
        lastDigits(a,m);
    else if(n==1)
        lastDigits(b,m);
    else
    {
        vvi ans = matrixPow(matrix, n);     // potencia n
        ans = matMul(ans, ini);             // mult por condiciones iniciales
        // cout<<ans[0][1]<<'\n';
        lastDigits(ans[1][0],m);
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
    matrix[0][0] = 1;
    matrix[0][1] = matrix[1][0] = 1;
    matrix[1][1] = 0;
    int t;cin>>t;
    while(t--)
        solve();
}