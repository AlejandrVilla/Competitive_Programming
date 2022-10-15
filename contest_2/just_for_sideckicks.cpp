#include <vector>
#include <map>
#include <set>
#include <iostream>
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define si set<int>
#define misi map<int,si>
#define LSOne(i) i & (-i)
using namespace std;

int large=200000;

vll FT(large+1,0);
vll gems(7);
misi pos;

int n,m;
string query;

void update(int i, ll v)
{
    while(i<=n)
    {
        FT[i] += v;
        i+=LSOne(i);
    }
}

void ini()
{
    for(int i=1 ; i<=n ; ++i)
    {
        update(i, gems[ int(query[i])-'0' ]);
        pos[int(query[i])-'0'].insert(i);
    }
}

ll rsq(int i)
{
    ll suma=0;
    while(i>0)
    {
        suma += FT[i];
        i-=LSOne(i);
    }
    return suma;
}

ll rsq(int i, int j)
{
    return rsq(j) - rsq(i-1);
}

void solve()
{
    cin>>n>>m;
    for(int i=1 ; i<=6 ; ++i)
        cin>>gems[i];
    string tmp;cin>>tmp;
    query=" "+tmp;
    ini();
    while(m--)
    {
        int op;cin>>op;
        if(op==1)
        {
            int k,p;cin>>k>>p;      // k gema en la cadena por p gema
            update(k,gems[p]- gems[ int(query[k])-'0' ]);
            pos[int(query[k])-'0'].erase(k);
            query[k] = char(p) + '0';
            pos[int(query[k])-'0'].insert(k);
        }
        else if(op==2)
        {   
            int p;
            ll v;cin>>p>>v;         // gema[p] = v
            for(auto it=pos[p].begin() ; it!=pos[p].end() ; ++it)
                update(*it,v-gems[p]);
            // for(int i=0 ; i<n ; ++i)
            //     if(query[i] == char(p) + '0')
            //         update(i+1,v-gems[p]);
            gems[p] = v;
        }
        else
        {
            int l,r;cin>>l>>r;
            cout<<rsq(l,r)<<'\n';
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