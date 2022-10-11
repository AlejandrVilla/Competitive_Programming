#include <vector>
#include <map>
#include <iostream>
#define ll long long int
#define vll vector<ll>
#define mvll map<ll,vll>
using namespace std;

ll n,m;
mvll adyacencia;

void solve()
{
    while(cin>>n>>m)
    {
        for(ll i=1 ; i<=n ; ++i)
        {
            ll num;
            cin>>num;
            adyacencia[num].push_back(i);
        }
        while(m--)
        {
            ll k,v;cin>>k>>v;
            if(k <= adyacencia[v].size())
                cout<<adyacencia[v][k-1]<<'\n';
            else
                cout<<"0\n";
        }
        adyacencia.clear();
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}