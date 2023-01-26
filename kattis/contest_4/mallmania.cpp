/*uva 11101*/
#include <iostream>
#include <vector>
#include <queue>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define qpii queue<pii>
#define MAX 2001
using namespace std;

vvi matrix;

vi pud = {1,-1,0,0};
vi plr = {0,0,-1,1};

void print()
{
    for(int i=0 ; i<MAX ; ++i)
    {
        for(int j=0 ; j<MAX ; ++j)
            cout<<matrix[i][j]<<' ';
        cout<<'\n';
    }
    cout<<'\n';
}

void solve(int n)
{
    qpii q;
    matrix.assign(MAX,vi(MAX,-1));
    while(n--)
    {
        int a,b;cin>>a>>b;
        matrix[b][a]=0;
        q.push({b,a});
    }
    cin>>n;
    while(n--)
    {
        int a,b;cin>>a>>b;
        matrix[b][a]=-2;
    }
    while(!q.empty())
    {
        // print();
        qpii aux;
    // cout<<"size "<<q.size()<<"\n";
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0 ; k<4 ; k++)
            {
                if( i+pud[k]<0 || i+pud[k]>=MAX || 
                    j+plr[k]<0 || j+plr[k]>=MAX ) continue;
                if( matrix[i+pud[k]][j+plr[k]] == -2 )
                {
                    cout<<matrix[i][j]+1<<'\n';
                    return;
                }
                else if( matrix[i+pud[k]][j+plr[k]] == -1 )
                {
                    matrix[i+pud[k]][j+plr[k]] = matrix[i][j]+1;
                    aux.push({i+pud[k],j+plr[k]});
                }
            }
        }
        q=aux;
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
    int t;
    while(cin>>t && t)
        solve(t);
}