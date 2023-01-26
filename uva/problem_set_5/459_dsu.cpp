#include <iostream>
#include <vector>
#include <set>
#define vi vector<int>
#define si set<int>
#define vvi vector<vi>
using namespace std;

vi parent;
si ncc;
int n;

void ini()
{
    for(int i=0 ; i<n ; ++i)
        parent[i]=i;
}

int par(int a)
{
    while(a != parent[a])
    {
        parent[a] = parent[parent[a]];
        a = parent[a];
    }
    return a;
}

void Union(int a,int b)
{
    a = par(a);
    b = par(b);
    if(a==b) return;
    parent[b]=a;
}

void solve()
{
    char c;cin>>c;
    n = int(c-'A')+1;
    parent.resize(n);
    ini();
    cin.ignore();
    string edge;
    while(getline(cin,edge) && edge!="")
        Union(int(edge[0]-'A'), int(edge[1]-'A'));
    for(int u=0 ; u<n ; ++u)
        ncc.insert(par(u));
    cout<<ncc.size()<<'\n';
    parent.clear();
    ncc.clear();
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
    {
        solve();
        if(t!=0)
            cout<<'\n';
    }
}