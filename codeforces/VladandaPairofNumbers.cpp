#include <bits/stdc++.h>
#define TEST(a,i) ((a) & (1<<(i)))      //comprueba si el i-esimo bit esta activado
#define SET(a,i) ((a) | (1<<(i)))       //activa el i-esimo bit
#define CLEAR(a,i) ((a) & ~(1<<(i)))    //desactiva el i-esimo bit
#define FLIP(a,i) ((a) ^ (1<<(i)))      //invertir el estado del i-esimo bit
#define LSO(n) ((n) & (-n))             //primer bit por la derecha
#define isPow(n) (((n) & (n)-1) == 0 && (n)) //potencia de 2
#define submask(a,b) ((a) & (b) == b)       //submascara
#define supmasl(a,b) ((a) | (b) == b)       //supermascara

using namespace std;

void solve()
{
    long long int x;cin>>x;
    long long int a,b;
    a=x, b=0;
    for(int i=32 ; i>=0 ; --i)
    {
        if(TEST(x,i)) continue;
        if(2*x - a - b >= (2LL<<i))
        {
        // cout<<a<<" "<<b<<" "<<i<<'\n';
            a += (1LL<<i);
            b += (1LL<<i);
        }
    }
    if(2*x == a+b && a^b == x)
        cout<<a<<" "<<b<<'\n';
    else
        cout<<-1<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
        solve();
}