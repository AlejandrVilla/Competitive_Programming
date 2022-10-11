#include <algorithm>
#include <vector>
#include <iostream>
#define ll long long int
#define vll vector<ll>
using namespace std;

vll arr;

void solve()
{
    ll num;
    while(cin>>num)
    {
        arr.push_back(num);
        sort(arr.begin(),arr.end());
        if(arr.size()%2!=0)
            cout<<arr[arr.size()/2]<<'\n';
        else
            cout<<(arr[arr.size()/2 - 1 ] + arr[arr.size()/2])/2<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}