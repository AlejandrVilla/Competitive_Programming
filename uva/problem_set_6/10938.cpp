#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#define vi vector<int>
#define vvi vector<vi>
#define MAX 5000
using namespace std;
enum {visitado=0 , novisitado=1};
vi L(2*MAX),E(2*MAX),H(MAX);
vi parent(MAX);
vi visited(MAX);
vvi tree;
int indx;

vvi st(MAX,L);
int n, max_f;

void ini()
{
    for(int i=0 ; i<n ; ++i)
        st[0][i] = i;
    for(int i=1 ; i<=max_f ; ++i)
    {
        for(int j=0 ; j + (1<<i) <= n ; ++j)
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
    if(L[st[j][a]] <= L[st[j][b-(1<<j)+1]])
        return st[j][a];
    return st[j][b-(1<<j)+1];
}

void dfs(int cur, int depth)
{
    visited[cur]=visitado;
    H[cur] = indx;      // aparicion
    E[indx] = cur;      // secuencia
    L[indx++] = depth;  // profundidad
    for(auto next : tree[cur])
    {
        if(visited[next]==novisitado)
        {
            parent[next] = cur;
            dfs(next, depth+1);
            E[indx] = cur;
            L[indx++] = depth;
        }
    }
}

int LCA(int a, int b)
{
    if(b<=a)
        return E[rmq(H[b],H[a])];
    return E[rmq(H[a],H[b])];
}

void solve()
{
    L.assign(2*MAX,0);
    E.assign(2*MAX,0);
    H.assign(MAX,0);
    st.assign(MAX,L);
    visited.assign(MAX,novisitado);
    parent.assign(MAX,-1);
    tree.resize(n);
    for(int i=0 ; i<n-1 ; ++i)
    {
        int a,b;cin>>a>>b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    indx=0;
    dfs(0,0);
    n = indx;
    max_f = log2(n);
    ini();
    int q;cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        l--;r--;
        int lca = LCA(l,r);
        int dist = L[H[l]] + L[H[r]] - 2*L[H[lca]];
        int low;
        if(L[H[l]] >= L[H[r]])      // mayor nivel
            low = l;
        else 
            low = r;
        for(int i=0 ; i<dist/2 ; ++i)
            low=parent[low];        // sube por el de mayor nivel
        if(dist%2==0)               // distancia par, se encuentran
            cout<<"The fleas meet at "<<low+1<<".\n";
        else                        // distancia impar, no se encuentran
            cout<<"The fleas jump forever between "<<min(low,parent[low])+1<<" and "<<max(low,parent[low])+1<<".\n";
    }
    tree.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n && n)
        solve();
}