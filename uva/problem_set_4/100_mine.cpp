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

void collats(int num, int& k)
{
    if(num==1) return;
    k++;
    if(num%2==0) collats(num/2, k);
    else collats(3*num+1,k);
}

void solve()
{
    int tmp_n,tmp_m;
    tmp_n = min(n,m);
    tmp_m = max(n,m);
    int max=0;
    for(int i=tmp_n; i<=tmp_m ; ++i)
    {
        int count=0;
        auto it=mem.find(i);
        if(it != mem.end())
        {
            count+=it->second;
        }
        else
        {
            collats(i,count);
            mem.insert({i,count});
        }
        if(count>max) max=count;
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