#include <bits/stdc++.h>
#define ll long long int
#define mll map<ll>
#define vb vector<bool>
#define sll set<ll>
using namespace std;

void solve()
{
    int n,m;
    while(cin>>n>>m && (n || m))
    {
        sll res;
        while(n--)
        {
            ll num;cin>>num;
            res.insert(num);
        }
        int c=0;
        int n_prev = res.size();
        while(m--)
        {
            ll num;cin>>num;
            res.insert(num);
            if(res.size() == n_prev)
                c++;
            else
                n_prev = res.size();
        }
        cout<<c<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}