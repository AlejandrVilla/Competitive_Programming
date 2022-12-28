#include <iostream>
#include <set>
#define sc set<char>
using namespace std;

int c;

void difDigits(string num)
{
    sc digits;
    for(int i=0 ; i<num.size() ; ++i)
        digits.insert(num[i]);
    if(digits.size() == num.size())
        c++;
}

void solve()
{
    int n,m;
    while(cin>>n>>m)
    {
        c=0;
        for(int i=n ; i<=m ; ++i)
            difDigits(to_string(i));
        cout<<c<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}