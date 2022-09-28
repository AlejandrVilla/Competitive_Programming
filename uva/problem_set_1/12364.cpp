#include <bits/stdc++.h>
using namespace std;

//                     0     1     2     3     4     5     6     7     8     9
vector<string> r1 = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
vector<string> r2 = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};
vector<string> r3 = {"..", "..", "..", "..", "..", "..", "..", "..", "..", ".."};

void solve()
{
    int D;
    while(cin>>D && D)
    {
        char s;cin>>s;
        if(s=='S')
        {
            string b;cin>>b;
            for(int i=0 ; i<b.size() ; ++i) 
            {
                cout<<r1[(int)b[i]-'0'];
                if(i!=b.size()-1)
                    cout<<' '; 
            }
            cout<<'\n';
            for(int i=0 ; i<b.size() ; ++i) 
            {
                cout<<r2[(int)b[i]-'0'];
                if(i!=b.size()-1)
                    cout<<' ';
            }
            cout<<'\n';
            for(int i=0 ; i<b.size() ; ++i) 
            {
                cout<<r3[(int)b[i]-'0'];
                if(i!=b.size()-1)
                    cout<<' ';
            }
            cout<<'\n';
        }
        else if(s=='B')
        {
            vector<string> i1(D),i2(D),i3(D);
            for(int i=0 ; i<D ; ++i) cin>>i1[i];
            for(int i=0 ; i<D ; ++i) cin>>i2[i];
            for(int i=0 ; i<D ; ++i) cin>>i3[i];
            string res;
            for(int i=0 ; i<D ; ++i)
                for(int j=0 ; j<r1.size() ; ++j)
                    if(i1[i] == r1[j] && i2[i] == r2[j] && i3[i] == r3[j])
                        cout<<j;
            cout<<'\n';
        }
    }
}

int main()
{
    solve();
}