#include <vector>
#include <iostream>
#define ll long long int
#define vll vector<ll>
using namespace std;

ll closest_sum(ll num, vll& A)
{
    ll dis=INT64_MAX;
    ll res=0;
    for(int i=0 ; i<A.size() ; ++i)
        for(int j=i+1 ; j<A.size() ; ++j)
            if(abs(A[i] + A[j] - num) < dis)
            {
                dis = abs(A[i] + A[j] - num);
                res = A[i] + A[j];
            }
    return res;
}

void solve()
{
    int n,m;
    int k=1;
    while(cin>>n)
    {
        cout<<"Case "<<k++<<":\n";
        vll arr(n);
        for(int i=0 ; i<n ; ++i)
            cin>>arr[i];
        cin>>m;
        while(m--)
        {
            ll q;cin>>q;
            cout<<"Closest sum to "<<q<<" is "<<closest_sum(q,arr)<<".\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    solve();
}