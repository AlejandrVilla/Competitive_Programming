#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define vb vector<bool>
using namespace std;

vll parent;
vll suma;
vll sp;
ll n,m;


void print(vll& A)
{
    for(ll i=0 ; i<A.size() ; ++i)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void ini()
{
    for(ll i=1 ; i<=n ; ++i)
    {
        parent[i] = n+i;
        parent[n+i] = n+i;
        suma[n+i] = i;
        suma[i] = i;
        sp[i] = 1;
        sp[n+i] = 1;
    }
}

ll par(ll a)
{
    while(parent[a] != a)
    {
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

void Union(ll p, ll q)
{
    ll a = par(p);
    ll b = par(q);
    if(a == b) return;
    suma[b] += suma[a];
    sp[b] += sp[a];
    parent[a] = b;
}

void Move(ll p, ll q)
{
    ll a = par(p);
    ll b = par(q);
    if(a == b) return;
    suma[a] -= p;
    suma[b] += p;
    sp[a]--;
    sp[b]++;
    parent[p] = b;
}

void solve()
{
    while(cin>>n>>m)
    {
        parent.resize(2*n+1);
        suma.resize(2*n+1);
        sp.resize(2*n+1);
        ini();
        while(m--)
        {
            int op;
            cin>>op;
            if(op==1)
            {
                ll a,b;
                cin>>a>>b;
                Union(a,b);
            }
            else if(op==2)
            {
                ll a,b;
                cin>>a>>b;
                Move(a,b);
            }
            else
            {
                ll a;
                cin>>a;
                cout<<sp[par(a)]<<' '<<suma[par(a)]<<'\n';
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    solve();
}