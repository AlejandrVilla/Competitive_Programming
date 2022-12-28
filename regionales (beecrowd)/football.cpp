#include <iostream>
#include <set>
#define msi multiset<int>
using namespace std;

void solve()
{
    int N,G;
    while(cin>>N>>G)
    {
        int points=0;
        msi loses;
        while(N--)
        {
            int S,R;cin>>S>>R;
            if(S>R) points+=3;
            else if(S==R) (G)?points+=3,G--:points++;
            else loses.insert(R-S);
        }
        for(auto it=loses.begin() ; it!=loses.end() && G ; ++it)
        {
            if((*it)+1<=G) 
            {
                G-=(*it)+1;
                points+=3;
            }
            else if((*it)==G)
            {
                G-=(*it);
                points++;
            }
        }
        cout<<points<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}