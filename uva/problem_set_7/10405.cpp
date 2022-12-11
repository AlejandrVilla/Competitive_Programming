#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define MAX 1001
using namespace std;

vvi table(MAX+1,vi(MAX+1,0));
int n,m;
string A,B;

void LCS()
{
    for(int i=0 ; i<=n ; ++i)
        table[i][0] = 0;
    for(int j=0 ; j<=m ; ++j)
        table[0][j] = 0;
    for(int i=1 ; i<=n ; ++i)
        for(int j=1 ; j<=m ; ++j)
        {
            if(A[i-1]==B[j-1])
                table[i][j] = table[i-1][j-1] + 1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]);
        }
}

void solve()
{
    while(getline(cin,A) && getline(cin,B))
    {
        n=A.size();
        m=B.size();
        LCS();
        cout<<table[n][m]<<'\n';
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
    solve();
}