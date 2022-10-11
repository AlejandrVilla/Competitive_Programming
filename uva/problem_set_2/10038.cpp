#include <bits/stdc++.h>
using namespace std;

void solve( int &n ) 
{
    int limit = n-1;
    vector<int>arr;
    vector<bool>oc(n,0);
    int num;
    for(int i=0;i<n;++i)
    {
        scanf( "%d" , &num );
        arr.push_back(num);
    }
    for(int i=0;i<n-1;++i)
    {
        if(  abs( arr[i]-arr[i+1] )>0 && abs( arr[i]-arr[i+1] )<= limit ) oc[abs(arr[i]-arr[i+1])] = 1 ;
    }
    for(int i=1;i<oc.size();++i)
    {
        if(!oc[i])
        {
            cout<<"Not jolly\n";
            return;
        }
    }
    cout<<"Jolly\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while( scanf( "%d" , &n ) != EOF )
    {
        solve(n);
    }
}