#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define vi vector<int>
using namespace std;

void solve()
{
    int l,n;cin>>l>>n;
    vi ants(n);
    for(int i=0 ; i<n; ++i)
        cin>>ants[i];
    sort(ants.begin(), ants.end());
    int dis=INT_MAX;
    int menor=0;
    for(int i=0 ; i<n ; ++i)
    {
        if(ants[i]<l/2)
            menor = max(menor, ants[i]);
        else
            menor = max(menor, l-ants[i]);
    }
    int mayor;
    if(ants.size()==1)
        mayor=max(ants[0],l-ants[0]);
    else
    {
        int may_l = ants[0] > l-ants[1]? ants[0] : l-ants[1];
        int may_r = ants[n-2] > l-ants[n-1]? ants[n-2] : l-ants[n-1];
        int mayor_l = may_l + ants[1]-ants[0];
        int mayor_r = may_r + ants[n-1] - ants[n-2];
        mayor = max(mayor_l, mayor_r);
        // mayor = (ants[1] - ants[0])%2 == 0? may+(ants[1]-ants[0]) : may+(ants[1]-ants[0]-1);
    }
    cout<<menor<<" "<<mayor<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--)
        solve();
}