#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;cin>>n;
    while(n--)
    {
        int A,F;cin>>A>>F;
        while(F--)
        {
            for(int i=1 ; i<=A ; ++i)
            {
                for(int j=0 ; j<i ; j++)
                    cout<<i;
                cout<<'\n';
            }
            for(int i=A-1 ; i>0 ; --i)
            {
                for(int j=0 ; j<i ; j++)
                    cout<<i;
                cout<<'\n';
            }
            if(F!=0)
                cout<<'\n';
        }
        if(n!=0)
            cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    solve();
}