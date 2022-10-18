#include <vector>
#include <iostream>
#include <algorithm>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
using namespace std;

void solve()
{
    
    int n,m;cin>>n>>m;
    vi row(m);
    vvi matrix(n,row);
    vpii edges;
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<m ; ++j)
            cin>>matrix[i][j];
    for(int j=0 ; j<m ; ++j)
    {
        vi edge;
        for(int i=0 ; i<n ; ++i)
        {
            if(matrix[i][j]==1)
                edge.push_back(i);
        }
        if(edge.size()!=2)
        {
            cout<<"No\n";
            return;
        }
        pii edge_ = {edge[0], edge[1]};
        if(find(edges.begin(), edges.end(), edge_) != edges.end())
        {
            cout<<"No\n";
            return;
        }
        edges.push_back(edge_);
    }
    cout<<"Yes\n";
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
    int N;cin>>N;
    while(N--)
        solve();
}