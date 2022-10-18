#include <vector>
#include <iostream>
#include <algorithm>
#define vi vector<int>
using namespace std;

int N,M,large=30000;
vi parent(large+1);
vi parentsize(large+1);

void ini()
{
    parent.clear();
    parentsize.clear();
    for(int i=1 ; i<=N ; ++i)
    {
        parent[i] = i;
        parentsize[i] = 1;
    }
}

int par(int a)
{
    while(a!=parent[a])
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
    if(a==b)
        return;
    parent[b] = a;
    parentsize[a]+=parentsize[b];
}

void solve()
{
    int n;cin>>n;
    while(n--)
    {
        cin>>N>>M;
        ini();
        while(M--)
        {
            int A,B;cin>>A>>B;
            Union(A,B);
        }
        int mayor=0;
        for(int i=1 ; i<=N ; ++i)
            mayor = max(mayor, parentsize[i]);
        cout<<mayor<<'\n';
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}
