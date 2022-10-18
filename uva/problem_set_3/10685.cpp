#include <vector>
#include <map>
#include <iostream>
#define vi vector<int>
#define msi map<string,int>
using namespace std;

int C,R,large=5000;
vi parent(large+1);
vi sizep(large+1);
msi creatures;

void ini()
{
    for(int i=1 ; i<=large ; ++i)
    {
        parent[i] = i;
        sizep[i] = 1;
    }
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

void Union(int a, int b)
{
    a=par(a);
    b=par(b);
    if(a==b)
        return;
    parent[b] = a;
    sizep[a] += sizep[b];
}

void solve()
{
    while(cin>>C>>R && (C || R))
    {
        ini();
        for(int i=1 ; i<=C ; ++i)
        {
            string creat;cin>>creat;
            creatures[creat] = i;
        }
        while(R--)
        {
            string A,B;cin>>A>>B;
            Union(creatures[A],creatures[B]);
        }
        int mayor=0;
        for(int i=1 ; i<=C ; ++i)
            mayor=max(mayor,sizep[i]);
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