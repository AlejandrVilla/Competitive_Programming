#include <bits/stdc++.h>
#define si set<int>
using namespace std;

void solve()
{
    int N,B,H,W;
    while(cin>>N>>B>>H>>W)
    {
        // si res;
        int aux = W;
        int min = B+1;
        while(H--)
        {
            int p;cin>>p;
            int tmp=0;
            aux = W;
            while(aux--)
            {
                int beds;cin>>beds;
                if(beds >= N && p*N <= min)
                    min = p*N;
            }
        }
        if(min <= B) 
            cout<<min<<'\n';
        else
            cout<<"stay home\n";
    }
}

int main()
{
    solve();
}