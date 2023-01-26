#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
using namespace std;

vi ud = {1,-1,0,0,1,1,-1,-1};
vi lr = {0,0,1,-1,-1,1,1,-1};
vs matrix;
int n,m;

void print()
{
    for(int i=0 ; i<n ; ++i)
        cout<<matrix[i]<<'\n';
}

void dfs(int f, int c)
{
    if(f<0 || f>=n || c<0 || c>=m)  return;
    if(matrix[f][c] == '*') return;
    matrix[f][c]='*';
    for(int i=0 ; i<8 ; ++i)
        dfs(f+ud[i], c+lr[i]);
}

void solve()
{
    matrix.resize(n);
    for(int i=0 ; i<n ; ++i)
        cin>>matrix[i];
    //print();
    int res=0;
    for(int f=0 ; f<n ; ++f)
        for(int c=0 ; c<m ; ++c)
            if(matrix[f][c]=='@')
            {
                res++;
                dfs(f,c);
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
    while(cin>>n>>m && (n||m))
        solve();
}