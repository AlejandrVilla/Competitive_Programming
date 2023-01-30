#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define mii map<int,int>
using namespace std;

enum{novisitado=0, visitado=1};
vi ud = {1,-1,0,0};
vi lr = {0,0,1,-1};
vvi matrix;
vvi visited;
int n,m;
int tmp;

void print(vvi& M)
{
    for(int f=0 ; f<n ; ++f)
    {
        for(int c=0 ; c<m ; ++c)
            cout<<M[f][c]<<" ";
        cout<<'\n';
    }
}

void bfs(int x, int y, bool& state)
{
    if(x<0 || y<0 || x>=n || y>=m)  return;
    if(visited[x][y] == visitado) return;
    visited[x][y]=visitado;
    tmp++;
    for(int i=0 ; i<4 ; ++i)
    {
        if(x+ud[i]<0 || y+lr[i]<0 || x+ud[i]>=n || y+lr[i]>=m) continue;
        if(matrix[x+ud[i]][y+lr[i]] < matrix[x][y])
            state=1;
        else if(matrix[x+ud[i]][y+lr[i]] == matrix[x][y])
            bfs(x+ud[i], y+lr[i], state);
    }
}

void solve()
{
    cin>>m>>n;
    matrix.assign(n,vi(m,0));
    visited.assign(n,vi(m,novisitado));
    for(int f=0 ; f<n ; ++f)
        for(int c=0 ; c<m ; ++c)
            cin>>matrix[f][c];
    int res=0;
    for(int f=0 ; f<n ; ++f)
        for(int c=0 ; c<m ; ++c)
        {
            if(visited[f][c] == novisitado)
            {
                bool state=0;
                tmp=0;
                bfs(f,c,state);
                if(!state) res+=tmp;
            }
        }
    cout<<res<<'\n';
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