#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
#define vvi vector<vi>
#define qi queue<int>
using namespace std;

vvi adjacent;
vi color;
int n,m;
bool ac=0;

void bicoloring()
{
    color[0]=0;
    qi q;q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v:adjacent[u])
        {
            if(color[v]==-1)
            {
                color[v] = 1-color[u];
                q.push(v);
            }
            else if(color[u]==color[v])
            {
                ac=1;
                return;
            }
        }
    }
}

void solve()
{
    while(cin>>n && n)
    {
        cin>>m;
        ac=0;
        adjacent.resize(n);
        color.resize(n,-1);
        while(m--)
        {
            int u,v;cin>>u>>v;
            adjacent[u].push_back(v);
        }
        bicoloring();
        if(!ac)
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
        adjacent.clear();
        color.clear();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}