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
    int n,k;cin>>n>>k;
    int res=INT32_MAX,or_=0;
    vector<int> arr(n);
    for(int i=0 ; i<n ; ++i)
    {
        cin>>arr[i];
        res &= arr[i];
        or_ |= arr[i];
    }
    int bit=30;
    while(k>=n && bit>=0) 
    {
        if(!(TEST(res,bit)) && !(TEST(or_,bit)))    // bit apagado en res y or
        {
            res = SET(res,bit); // prende en res
            k-=n;
        }
        bit--;
    }
    bit=30;
    while(!(TEST(or_,bit)) && bit>=0) bit--;    // hasta encontrar bit prendido
    while(bit>=0)
    {
        int c=0;
        if(TEST(or_,bit) && !(TEST(res,bit)))   // bit encendido en or y apagado en res
        {
            for(int i=0 ; i<n ; ++i)   
                if(!(TEST(arr[i],bit)))     // por cada bit apagado
                    c++;    // acumula
            if(k>=0 && c<=k) 
            {
                res = SET(res,bit);
                k-=c;
            }
        }
        bit--;
    }
    cout<<res<<'\n';
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