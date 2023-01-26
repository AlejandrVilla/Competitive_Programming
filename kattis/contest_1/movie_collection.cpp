#include <vector>
#include <iostream>
#define vi vector<int>
using namespace std;

int m,r;
int large = 100000;
int i_c;
vi FT(2*large+1,0);
vi indices(2*large+1,0);
vi arr(large+1,0);

void print(vi& A)
{
    for(int i=0 ; i<=m ; ++i)
        cout<<i<<' ';
    cout<<'\n';
    for(int i=i_c ; i<=i_c+m ; ++i)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void update(int i, int val)
{
    while(i<=large+m)
    {
        FT[i] += val;
        i += i & (-i);
    }
}

void ini()
{
    for(int i=0 ; i<=large ; ++i)
    {
        indices[i] = 0;
        FT[i] = 0;
    }
    for(int i=1 ; i<=m ; ++i)
    {
        FT[large+i] = 0;
        arr[i] = large+i;
        indices[large+i] = 1;
    }
    for(int i=large+1 ; i<=large+m ; ++i)
        update(i,indices[i]);
}

int rsq(int i)
{
    i--;
    int suma=0;
    while(i>i_c)
    {
        suma += FT[i];
        i -= i & (-i);
    }
    return suma;
}

void solve()
{
    int n;cin>>n;
    while(n--)
    {
        cin>>m>>r;
        i_c = large;
        ini();
        while(r--)
        {
            int req;cin>>req;
            cout<<rsq(arr[req])<<'\n';
            update(arr[req],-1);
            indices[arr[req]] = 0;
            arr[req] = i_c;
            update(arr[req],1);
            indices[i_c] = 1;
            i_c--;
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