#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define ll long long int
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define MAX 102
using namespace std;
enum{inf=INT32_MAX};

vvll adjacent(MAX,vll(MAX,0));
int n;

void init()
{
    loop(i,0,n)
        loop(j,0,n)
            adjacent[i][j]=inf;
    loop(i,0,n)
        adjacent[i][i]=0;
}

void floyd_warshall()
{
    loop(k,0,n)
        loop(i,0,n)
            loop(j,0,n)
                adjacent[i][j] = min(adjacent[i][j],adjacent[i][k]+adjacent[k][j]);
}

void setpath(int a, int b, string c)
{
    adjacent[a][b]=adjacent[b][a]=stoi(c);
}

void print()
{
    loop(i,0,n)
    {
        loop(j,0,n)
            cout<<adjacent[i][j]<<' ';
        cout<<'\n';
    }
}

void solve()
{
    while(cin>>n)
    {
        init();
        string num;
        loop(i,0,n-1)
            loop(j,0,i+1)
            {
                cin>>num;
                if(num=="x")continue;
                setpath(i+1,j,num);	
            }
        floyd_warshall();
        // print();
        cout<<*max_element(adjacent[0].begin(),adjacent[0].begin()+n)<<'\n';
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