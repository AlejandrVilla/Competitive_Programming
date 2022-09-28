#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

vi parent;
vi range;

int par(int a)
{
    while(parent[a] != a)
        a = parent[a];
    return a;
}

void Union(int v1, int v2)
{
    int a = par(v1);
    int b = par(v2);
    if(a==b) return;
    if(range[a] < range[b])
        parent[a] = b;
    else if(range[b] < range[a])
        parent[b] = a;
    else
    {
        parent[b] = a;
        range[a]++;
    }
}

bool isConnected(int v1, int v2)
{
    int a = par(v1);
    int b = par(v2);
    if(a==b)
        return 1;
    return 0;
}

void solve()
{
    int n,q;cin>>n>>q;
    parent.resize(n);
    range.resize(n);
    for(int i=0 ; i<n ; ++i)
    {
        parent[i] = i;
        range[i] = 1;
    }
    while(q--)
    {
        char o;
        int a,b;
        cin>>o>>a>>b;
        if(o == '=')
            Union(a,b);
        else if(o == '?')
        {
            if(isConnected(a,b))
                cout<<"yes\n";
            else
                cout<<"no\n";
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