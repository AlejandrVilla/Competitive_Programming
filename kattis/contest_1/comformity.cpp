#include <bits/stdc++.h>
#define ss set<string>
#define msi map<string,int>
using namespace std;

void solve()
{
    int n;cin>>n;
    msi res;
    while(n--)
    {
        ss cursos;
        for(int i=0 ; i<5 ; ++i)
        {
            string num;cin>>num;
            cursos.insert(num);
        }
        string codigo;
        for(auto a:cursos)
            codigo += a;
        res[codigo]++;
    }
    int max=0;
    for(auto a:res)
        if(a.second > max)
            max=a.second;
    int cont=0;
    for(auto a:res)
        if(a.second == max)     // acumula cantidad de personas que tienen la mayor combinacion
            cont+=a.second;
    cout<<cont<<'\n';
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    solve();
}