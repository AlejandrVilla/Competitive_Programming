#include <iostream>
#include <math.h>
#include <vector>
#define ll long long int
#define vll vector<ll>
#define vvll vector<vll>
#define pill pair<int,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vpill vector<pill>
#define vvpill vector<vpill>
#define NMAX 100000
#define MAXTABLE 500
using namespace std;
enum {visitado=0 , novisitado=1};

vvpill tree(NMAX);
vi visited(NMAX,novisitado);
int n;

vi A(NMAX),S(2*NMAX);
vll L(2*NMAX);
int indx;

vvll st(MAXTABLE,L);
int max_f;

void dfs(int c, ll depth)
{
    visited[c] = visitado;
    A[c] = indx;                // aparicion
    S[indx] = c;                // secuencia
    L[indx++] = depth;          // profundidad
    for(auto v : tree[c])       // v, w
    {
        if( visited[v.first] == novisitado )
        {
            dfs(v.first, depth+v.second);       // acumula pesos como prufundidad
            S[indx] = c;
            L[indx++] = depth;
        }
    }
}

void ini()
{
    for(int i=0 ; i<n ; ++i)
        st[0][i]=i;
    for(int i=1 ; i<=max_f ; ++i)
    {
        for(int j=0 ; j+(1<<i) <= n ; ++j)
        {
            if(L[st[i-1][j]] <= L[st[i-1][j+(1<<(i-1))]])
                st[i][j] = st[i-1][j];
            else
                st[i][j] = st[i-1][j+(1<<(i-1))];
        }
    }
}

int rmq(int a, int b)
{
    if(b<a) swap(a,b);
    int j=log2(b-a+1);
    if(L[st[j][a]] <= L[st[j][b-(1<<j)+1]])     // menor nivel de las primeras apariciones entre a y b
        return st[j][a];
    return st[j][b-(1<<j)+1];
}

int LCA(int a, int b)
{
    if(b<a)
        return S[rmq(A[b],A[a])];       // entre la primera aparicion de a y b
    return S[rmq(A[a],A[b])];
}

void solve()
{
    while(cin>>n && n)
    {
        tree.resize(n);
        visited.assign(n,novisitado);
        for(int i=1 ; i<=n-1 ; ++i)
        {
            int v;ll w;cin>>v>>w;
            tree[i].push_back({v,w});
            tree[v].push_back({i,w});
        }
        indx=0;
        dfs(0,0);
        n=indx;
        max_f=log2(n);
        ini();
        int q;cin>>q;
        while(q--)
        {
            int u,v;cin>>u>>v;
            int lca = LCA(u,v);
            ll res = L[A[u]] + L[A[v]] - 2*L[A[lca]];
            cout<<res;
            if(q!=0)
                cout<<" ";
        }
        cout<<'\n';
        tree.clear();
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
    solve();
}