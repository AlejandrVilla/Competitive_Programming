#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define mii map<int,int>
using namespace std;

int n,m;
mii mem;

int freq(int n)
{
    if(n==1) return 0;
    if(mem.count(n)) return mem[n];
    int val=1;
    if(n%2==0) val+=freq(n/2);
    else val+=freq(3*n+1);
    mem[n] = val;
    return val;
}

void solve()
{
    int tmp_n,tmp_m;
    tmp_n = min(n,m);
    tmp_m = max(n,m);
    int max=0;
    for(int i=tmp_n; i<=tmp_m ; ++i)
    {
        int tmp=freq(i);
        if(tmp>max) max=tmp;
    }
    cout<<n<<" "<<m<<" "<<max+1<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n>>m)
        solve();
}