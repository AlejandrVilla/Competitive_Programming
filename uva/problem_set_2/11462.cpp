#include <set>
#include <iostream>
#define ll long long int
#define mll multiset<ll>
using namespace std;

mll arr;

void print(mll& A)
{
    int i=1;
    for(auto it = A.begin() ; it!= A.end() ; ++it, ++i)
    {
        cout<<*it;
        if(i!=A.size())
            cout<<' ';
    }
    cout<<'\n';
}

void solve()
{
    int n;
    while(cin>>n && n)
    {
        for(int i=0 ; i<n ; ++i)
        {
            int num;cin>>num;
            arr.insert(num); 
        }
        print(arr);
        arr.clear();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}