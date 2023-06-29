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
    int n;cin>>n;
    if(n%2!=0)
        cout<<-1<<'\n';
    else
        cout<<0<<" "<<n/2<<" "<<n/2<<'\n';
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