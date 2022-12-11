#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum {novisitado=0, visitado=1};
vvi adjacent;
vi match;
vi visited;
int n,m;

int MVC(int L)
{
    if(visited[L]==visitado) return 0;
    visited[L] = visitado;
    for(int R : adjacent[L])
    {
        if(match[R] == -1 || MVC(match[R]))
        {
            match[R]=L;
            return 1;
        }
    }
    return 0;
}

void solve()
{
    cin>>n;
    vi A(n);
    for(int i=0 ; i<n ; ++i) cin>>A[i];
    cin>>m;
    vi B(m);
    for(int i=0 ; i<m ; ++i) cin>>B[i];
    adjacent.resize(n+m);
    match.assign(n+m,-1);
    for(int i=0 ; i<m ; ++i)
        for(int j=0 ; j<n ; ++j)
        {
            if(B[i]==0 && A[j]==0)      // 0 multiplo 0
                adjacent[n+i].push_back(j),adjacent[j].push_back(n+i);
            if(A[j]==0)            // no hay division por 0
                continue;
            else if(B[i]%A[j]==0)
                adjacent[n+i].push_back(j),adjacent[j].push_back(n+i);
        }
    int mvc=0;
    for(int i=0 ; i<n ; ++i)
    {
        visited.assign(n,novisitado);
        mvc+=MVC(i);
    }
    cout<<mvc;
    adjacent.clear();
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
    for(int i=1 ; i<=t ; ++i)
    {
        cout<<"Case "<<i<<": ";
        solve();
        cout<<'\n';
    }
}