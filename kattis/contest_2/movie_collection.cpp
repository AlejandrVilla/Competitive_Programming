#include <iostream>
#include <vector>
#define ll long long int
#define vll vector<ll>
#define vi vector<int>
#define LSOne(i) ((i) & (-(i)))
using namespace std;

ll large = 100000;
vi arr(large+1,0);
vi FT(2*large+1);
vi indices(2*large+1);

int m,r;
int c_i=large;

void update(int i, int v)
{
    while(i<=large+m)
    {
        FT[i] += v;
        i+=LSOne(i);
    }
}

void ini()
{
    for(int i=0 ; i<=large ; ++i)
    {
        // arr[i] = 0;
        FT[i] = 0;
        indices[i] = 0;
    }
    for(int i=1 ; i<=m ; ++i)
    {
        indices[large+i] = 1;
        arr[i] = large+i;
        FT[large+i] = 0;
    }
    for(int i=large+1 ; i<=large+m ; ++i)
        update(i,indices[i]);
}

int rsq(int i)
{
    i--;
    int sum=0;
    while(i>c_i)
    {
        sum+=FT[i];
        i-=LSOne(i);
    }
    return sum;
}

void solve()
{
    int n;cin>>n;
    while(n--)
    {
        cin>>m>>r;
        c_i = large;
        ini();
        while(r--)
        {
            int a;cin>>a;
            cout<<rsq(arr[a])<<'\n';
            update(arr[a],-1);
            indices[arr[a]] = 0;
            indices[c_i] = 1;
            arr[a] = c_i;
            update(c_i,1);
            c_i--;
        }   
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}