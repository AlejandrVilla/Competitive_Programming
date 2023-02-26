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
#define MAX 100000000
using namespace std;

vi ud = {0,1,1, 1, 0,-1,-1,-1};
vi lr = {1,1,0,-1,-1,-1,0, 1};
vstr matrix;
int n,cnt;
bool eagle=0,curr;

void bfs(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=n) return;
    if(matrix[x][y] == '2') return;
    if(curr && matrix[x][y] == '1')
    {
        matrix[x][y] = '2';
        eagle=1;
        loop(i,0,8)
            bfs(x+ud[i],y+lr[i]);
    }
    else if(!curr && matrix[x][y] == '0')
    {
        matrix[x][y] = '2';
        loop(i,0,8)
            bfs(x+ud[i],y+lr[i]);
    }
}

void solve()
{
    string row;
    cnt=0;
    loop(i,0,n)
    {
        cin>>row;
        matrix.push_back(row);
    }
    loop(i,0,n)
        loop(j,0,n)
        {
            if(matrix[i][j] == '1') curr = 1;
            else if(matrix[i][j] == '0') curr = 0;
            eagle=0;
            bfs(i,j);
            if(eagle)
                cnt++;
        }
    matrix.clear();
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
    while(cin>>n)
    {
        solve();
        cout<<"Image number "<<i++<<" contains "<<cnt<<" war eagles.\n";
    }
}