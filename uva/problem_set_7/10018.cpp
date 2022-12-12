#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool ispalindromo(string& s)
{
    int m=s.size()/2;
    int i=0, j=s.size()-1;
    while(i<=j)
    {
        if(s[i]!=s[j]) return 0;
        i++;j--;
    }
    return 1;
}

void solve()
{
    ll num;cin>>num;
    string num_s = to_string(num);
    int c=0;
    do
    {
        reverse(num_s.begin(),num_s.end());
        ll num2 = stoi(num_s);
        num = num + num2;
        num_s=to_string(num);
        c++;
    }
    while(!ispalindromo(num_s));
    cout<<c<<" "<<num<<'\n';
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