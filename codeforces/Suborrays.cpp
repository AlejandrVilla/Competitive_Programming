#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> res(n,0);
    for(int i=0 ; i<n ; ++i)
        res[i]=i+1;
    for(int i=0 ; i<n ; ++i)
        cout<<res[i]<<' ';
    cout<<'\n';
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