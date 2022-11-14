#include <iostream>
#include <vector>
#define vs vector<string>
#define vi vector<int>
using namespace std;

vs matrix;
int t,n;
int res=0;

//         S  E  N  W
vi pud = { 1, 0,-1, 0};
vi plr = { 0, 1, 0,-1};

void ships(int i, int j)
{
    if(i<0 || i>=matrix.size()) return;
    if(j<0 || j>=matrix.size()) return;
    if(matrix[i][j] == '.') return;
    matrix[i][j]='.';
    for(int k=0 ; k<4 ; ++k)
        ships(i+pud[k], j+plr[k]);
}

void solve()
{
    cin>>n;
    res=0;
    while(n--)
    {
        string row;cin>>row;
        matrix.push_back(row);
    }
    for(int i=0 ; i<matrix.size() ; ++i)
    {
        for(int j=0 ; j<matrix.size() ; ++j)
        {
            if(matrix[i][j]=='x')
            {
                res++;
                ships(i,j);
            }
        }
    }
    cout<<res<<'\n';
    matrix.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>t;
    for(int i=1 ; i<=t ; ++i)
    {
        cout<<"Case "<<i<<": ";solve();
    }
}