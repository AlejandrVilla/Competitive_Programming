#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int n;

void solve()
{
    cin>>n;
    arr.assign(n,0);
    for(int i=0 ; i<n ; ++i)
        cin>>arr[i];
    int res=INT32_MAX;
    for(int i=0 ; i<n ; ++i)
        res=res&arr[i];
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