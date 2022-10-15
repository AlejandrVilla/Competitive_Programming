#include <vector>
#include <iostream>
#define vi vector<int>
#define vb vector<bool>
#define LSOne(i) ((i) & -(i))
using namespace std;

int large=1000000;
vb arr(large+1,0);
vi FT(large+1,0);

int n,k;

void update(int i, int v)
{
    while(i<=n)
    {
        FT[i] += v;
        i+=LSOne(i);
    }
}

int rsq(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=FT[i];
        i-=LSOne(i);
    }
    return sum;
}

int rsq(int i, int j)
{
    return rsq(j) - rsq(i-1);
}

void solve()
{

    cin>>n>>k;
    while(k--)
    {
        char op;cin>>op;
        if(op == 'F')
        {
            int i;cin>>i;
            if(arr[i])
                update(i,-1);
            else
                update(i,1);
            arr[i] = !arr[i];
        }
        else
        {
            int i,j;cin>>i>>j;
            cout<<rsq(i,j)<<'\n';
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