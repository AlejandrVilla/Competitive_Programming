#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <iomanip>
#include <map>
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
#define mii map<int,int>
#define si set<int>
#define sc set<char>
#define sll set<ll>
#define msi multiset<int>
#define MAX 100000000
using namespace std;

string A,B;
vstr VA,VB;
vvi table;

bool isWord(char c)
{
    if( (c>='A' && c<='Z') || (c>='a' && c<='z')) return 1;
    if( c>='0' && c<='9') return 0;
    return 0;
}

void clean(string& str)
{
    loop(i,0,str.size())
        if(!isalnum(str[i]))
            str[i]=' ';
}

void solve()
{
    getline(cin,B);
    clean(A);
    clean(B);
    stringstream linea1(A),linea2(B);
    string word1,word2;
    while(getline(linea1,word1,' '))
        if(word1!="") VA.push_back(word1);
    while(getline(linea2,word2,' '))
        if(word2!="") VB.push_back(word2);
    int n=VA.size();
    int m=VB.size();
    table.assign(n+1,vi(m+1,0));
    loop(i,1,n+1)
    {
        loop(j,1,m+1)
        {
            if(VA[i-1]==VB[j-1]) table[i][j] = table[i-1][j-1]+1;
            else table[i][j] = max(table[i-1][j],table[i][j-1]);
        }
    }
    if(VB.size() && VA.size())
        cout<<"Length of longest match: "<<table[n][m]<<'\n';
    else
        cout<<"Blank!\n";
    VA.clear();
    VB.clear();
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=1;
    while(getline(cin,A))
    {
        printf("%2d. ",i++);
        solve();
    }
}