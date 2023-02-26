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
#define MAX 1000002
using namespace std;

string T,P;
int n,m,cnt,mayor;
vi b(MAX);

void kmpProcess()
{
    int i=0, j=-1;
    b[0]=-1;
    while(i<m)
    {
        while(j>=0 && P[i]!=P[j]) j=b[j];
        i++, j++;
        b[i]=j;
    }
}

void KMP()
{
    int i=0,j=0,k=0;
    while(i<n)
    {
        while(j>=0 && T[i]!=P[j]) j=b[j];
        i++,j++,k++;
        if(j==m && i%(m)==0) 
        {
            cnt++; 
            j=b[j];
        }
    }
}

void solve()
{
    mayor=0;
    n=T.size();
    loop(i,1,n+1)
    {
        if(n%i!=0) continue;
        cnt=0;
        P=T.substr(0,i);
        m=P.size();
        kmpProcess();
        KMP();
        if(cnt == n/i) 
            mayor=max(mayor,cnt);
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
    while(cin>>T && T!=".")
        solve();
}
