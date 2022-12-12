#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

bool compare(char a, char b)
{
    if(tolower(a) == tolower(b))
        return a<b;
    return tolower(a) < tolower(b);
}

void solve()
{
    string s;cin>>s;
    sort(s.begin(),s.end(),compare);
    cout<<s<<'\n';
    while(next_permutation(s.begin(),s.end(),compare))
        cout<<s<<'\n';
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
        solve();
}