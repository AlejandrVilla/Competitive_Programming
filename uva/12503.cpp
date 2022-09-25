#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        vector<string> instructions;
        int pos = 0;
        while(n--)
        {
            string inst;cin>>inst;
            if(inst != "LEFT" && inst != "RIGHT")
            {
                int i;cin>>inst>>i;
                instructions.push_back( instructions[ i - 1] );
            }
            else
                instructions.push_back(inst);
        }
        for(auto a: instructions)
        {
            if(a == "LEFT")
                pos -= 1;
            else
                pos += 1;
        }
        cout<<pos<<'\n';
    }
}

int main()
{
    solve();
}