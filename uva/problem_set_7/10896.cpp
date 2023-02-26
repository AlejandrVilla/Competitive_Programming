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

string encryp;
string token;
sc res;

void decrypt(const string& word)
{   
    loop(i,0,27)
    {
        string aux=token;
        loop(j,0,aux.size())
            aux[j]=char('a'+((aux[j]-'a')+i)%26);
        if(aux==word)
        {
            res.insert(char('a'+i));
            return;
        }
    }
}

void solve()
{
    getline(cin,encryp);
    getline(cin,token);
    stringstream linea(encryp);
    string word;
    while(getline(linea,word,' '))
        if(word.size() == token.size())
            decrypt(word);
    for(auto a:res) cout<<a;
    cout<<'\n';
    res.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    cin.ignore();
    while(t--)
        solve();
}