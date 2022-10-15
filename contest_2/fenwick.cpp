#include <vector>
#include <iostream>
#define ll long long int
#define vll vector<ll>
#define LSOne(i) i & (-i)

using namespace std;

vll arr,FT;
ll n,q;

void update(ll i, ll v)
{
    while(i<=n)
    {
        FT[i] += v;
        i+=LSOne(i);
    }
}

ll rsq(ll i)
{
    ll sum=0;
    while(i>0)
    {
        sum+=FT[i];
        i -= LSOne(i);
    }
    return sum;
}

void solve()
{
    cin>>n>>q;
    // arr.resize(n,0);
    FT.resize(n+1,0);
    while(q--)
    {
        char op;cin>>op;
        if(op=='+')
        {
            ll i,v;cin>>i>>v;
            update(i+1,v);
        }
        else
        {
            ll i;cin>>i;
            cout<<rsq(i)<<'\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}