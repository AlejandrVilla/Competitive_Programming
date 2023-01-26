#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define vs vector<string>
#define pii pair<int,int>
#define qpii queue<pii>
#define vi vector<int>
using namespace std;

int n,m;
vs matrix;
int res;
bool c;

vi ud = {-1,0,1,0};
vi lr = {0,1,0,-1};

void gold(int x, int y)
{
    qpii Q;
    Q.push({x,y});
    while(!Q.empty())
    {
        x=Q.front().first;
        y=Q.front().second;
        Q.pop();
        if(matrix[x][y]=='#' || matrix[x][y]=='T') continue;
        if(matrix[x][y]=='G') res++;
        matrix[x][y] = '#';
        c=0;
        for(int i=0 ; i<4 ; ++i)
        {
            if(matrix[x+ud[i]][y+lr[i]]=='T')
            {
                c=1;
                break;
            }
        }
        for(int i=0 ; i<4 && !c; ++i)
            Q.push({x+ud[i],y+lr[i]});
    }
}

void solve()
{
    matrix.resize(n);
    for(int i=0 ; i<n ; ++i)
        cin>>matrix[i];
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<m ; ++j)
            if(matrix[i][j]=='P')
            {
                res=0;
                gold(i,j);
                cout<<res<<"\n";
                return;
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
    while(cin>>m>>n)
        solve();
}