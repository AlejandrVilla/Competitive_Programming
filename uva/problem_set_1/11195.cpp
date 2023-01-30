#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vs vector<string>
#define vc vector<char>
#define mii map<int,int>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define MAX 15
#define GET(x,i) ((x) & (1<<(i)))
#define SET(x,i) x = ((x) | (1<<(i)))
#define OFF(x,i) x = ((x) & ~(1<<(i)))
using namespace std;

int n;
int cont=0;
vs matrix(MAX);
vc table(MAX);
int diagizq;
int diagder;
int row;

bool ataca(int i, int c)
{
    if( GET(row,i) || 
        GET(diagizq, i+c) || 
        GET(diagder, i-c+n)) return 1;
    return 0;
}

void nReinas(int ind)
{
    if(ind==n) 
    {
        cont++;
        return;
    }
    loop(i,0,n)
    {
        if(matrix[i][ind]=='*')continue;
        table[ind]=char(i);
        if(!ataca(i,ind))
        {
            SET(row, i);
            SET(diagizq, i+ind);
            SET(diagder, i-ind+n);
            nReinas(ind+1);
            OFF(row, i);
            OFF(diagizq, i+ind);
            OFF(diagder, i-ind+n);
        }
    }
}

void solve()
{
    cont=0;
    for(int i=0 ; i<n ; ++i)
        cin>>matrix[i];
    diagder=0;
    diagizq=0;
    row=0;
    nReinas(0);
    cout<<cont;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=1;
    while(cin>>n && n)
    {
        cout<<"Case "<<i++<<": ";
        solve();
        cout<<'\n';
    }
}