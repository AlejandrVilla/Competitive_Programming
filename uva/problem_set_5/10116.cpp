#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
using namespace std;
vs matrix;
vvi visited;
bool bucle=0;
int n,m,c;

void solve()
{
    c--;
    matrix.resize(n);
    visited.assign(n,vi(m,0));
    for(int i=0 ; i<n ; ++i)
        cin>>matrix[i];
    int f=0;
    int steps=1;
    while( f>=0 && c>=0 && f<n && c<m)
    {
        if(visited[f][c]!=0)
        {
            cout<<visited[f][c]-1<<" step(s) before a loop of "<<steps-visited[f][c]<<" step(s)\n";
            return;
        }
        visited[f][c]=steps++;
        if(matrix[f][c] == 'W') c--;
        else if(matrix[f][c] == 'E') c++;
        else if(matrix[f][c] == 'N') f--;
        else if(matrix[f][c] == 'S') f++;
    }
    cout<<steps-1<<" step(s) to exit\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m>>c && (n || m || c))
        solve();
}