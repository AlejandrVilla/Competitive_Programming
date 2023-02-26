#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define vstr vector<string>
#define ll long long int
#define tiii tuple<int,int,int>
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define uomstri unordered_map<string,int>
#define mii map<int,int>
#define si set<int>
#define sc set<char>
#define sll set<ll>
#define msi multiset<int>
#define MAX 26
using namespace std;

vi ud = {0,1,1, 1, 0,-1,-1,-1};
vi lr = {1,1,0,-1,-1,-1, 0,1};

vstr matrix(MAX);
int n,m,mayor,unos;

void bfs(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m) return;
    if(matrix[x][y] == '0') return;
    matrix[x][y] = '0';
    unos++;
    loop(i,0,8)
        bfs(x+ud[i],y+lr[i]);
}

void solve()
{
    int i=0;
    n=0;
    string row;
    while(getline(cin,row) && row!="")
    {
        matrix[i++]=row;
        n++;
    }
    m=matrix[0].size();
    mayor=0;
    loop(i,0,n)
        loop(j,0,m)
            if(matrix[i][j] == '1')
            {
                unos=0;
                bfs(i,j);
                mayor=max(mayor,unos);
            }
    cout<<mayor<<'\n';
}   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;cin.ignore();
    cin.ignore();
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<'\n';
    }
}