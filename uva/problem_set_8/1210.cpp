#include <iostream>
#include <vector>
#include <bitset>
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define MAX 10001
using namespace std;

bitset<MAX> criba;
int criba_size;
vll primos;
vi res(MAX,0);

void setCriba()
{
    criba_size = MAX;
    criba.set();
    criba[0] = criba[1] = 0;
    for(int i=2 ; i<criba_size ; ++i)
    {
        if(criba[i])
        {
            for(int j=i*i ; j<criba_size ; j+=i)
                criba[j]=0;
            primos.push_back(i);
        }
    }
}

void solve()
{
    setCriba();
    for(int i=1 ; i<primos.size() ; ++i)
    {
        ll ac=primos[i];
        for(int j=i-1 ; j>=0 ; --j)
        {
            ac+=primos[j];
            if(ac>=MAX) break;
            res[ac]++;
        }
    }
    int n;
    while(cin>>n && n)
    {
        int r=res[n];
        if(criba[n])
            r++;
        cout<<r<<'\n';
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