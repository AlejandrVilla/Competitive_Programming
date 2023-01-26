#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define si set<int>
using namespace std;

vi numeros;
si res;

void solve()
{
    int n;
    while(cin>>n)
    {
        int limit = n-1;
        for(int i=0 ; i<n ; ++i)
        {
            int num;
            cin>>num;
            numeros.push_back(num);
        }
        for(int i=0 ; i<n-1 ; ++i)
        {
            int resta = abs(numeros[i]-numeros[i+1]);
            if( resta > 0 && resta <= limit) 
                res.insert(resta);
        }
        if(res.size() == n-1)
            cout<<"Jolly\n";
        else
            cout<<"Not Jolly\n";
        numeros.clear();
        res.clear(); 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}