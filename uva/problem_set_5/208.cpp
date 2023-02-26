#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define vstr vector<string>
#define ll long long int
#define tiii tuple<int,int,int>
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vbl vector<bool>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define uomstri unordered_map<string,int>
#define mii map<int,int>
#define si set<int>
#define sc set<char>
#define sll set<ll>
#define vsi vector<si>
#define uomisi unordered_map<int,si>
#define msi multiset<int>
#define MAX 22
using namespace std;

enum{novisitado=0, visitado=1};
uomisi adjacent;
vbl visited;
vi res;
int last;
int ct;

void prune(int i)           // poda todos los caminos que no llegan a last
{
    if(visited[i] == novisitado) return;
    visited[i] = novisitado;
    for(auto v : adjacent[i])
        prune(v);
}

void dfs(int u)
{
    if(u==last-1)

    {
        loop(i,0,res.size())
        {
            cout<<res[i]+1;
            if(i!=res.size()-1)
                cout<<' ';
        }
        cout<<'\n';
        ct++;
        return;
    }
    for(auto v:adjacent[u])
    {
        if(visited[v]==novisitado)
        {
            visited[v]=visitado;    
            res.push_back(v);
            dfs(v);
            visited[v]=novisitado;
            res.pop_back();
        }
    }
}

void solve()
{
    int u,v;
    ct=0;
    while(cin>>u>>v && (u || v))
    {
        adjacent[u-1].insert(v-1);
        adjacent[v-1].insert(u-1);
    }
    visited.assign(last,visitado);
    prune(last-1);
    res.push_back(0);
    visited[0] = visitado;
    dfs(0);
    cout<<"There are "<<ct<<" routes from the firestation to streetcorner "<<last<<".\n";
    adjacent.clear();
    res.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int i=1;
    while(cin>>last)
    {
        cout<<"CASE "<<i++<<":\n";
        solve();
    }
}


// #include <bits/stdc++.h>
// using namespace std;

// int ans=0;

// // prune impossible graph/node with single dfs
// void prune(int idx,unordered_map<int,set<int>>& graph,
//          vector<bool>& visited){
//     if(!visited[idx]) return;
//     visited[idx] = false; // allow visit in next dfs
//     for(auto& neigh : graph[idx])
//         prune(neigh,graph,visited);
// }

// void dfs(int idx,unordered_map<int,set<int>>& graph,
//          vector<bool>& visited,vector<int>& cur){
//     if(idx == visited.size()-1){
//         ans++;
//         // for(auto& v : cur){
//         //     cout << (v+1);
//         //     if(&v == &cur.back()) cout << endl;
//         //     else cout << " ";
//         // }
//         return;
//     }
//     for(auto& neigh : graph[idx]){
//         if(!visited[neigh]){
//             visited[neigh] = true;
//             cur.push_back(neigh);
//             dfs(neigh,graph,visited,cur);
//             visited[neigh] = false;
//             cur.pop_back();
//         }
//     }
// }

// int main()
// {
//     // ios::sync_with_stdio(false);
//     // cin.tie(0); cout.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt","r",stdin);
//         freopen("output.txt","w",stdout);
//     #endif
//     int n,tc=1;
//     int a,b;
//     while(cin >> n){
//         unordered_map<int,set<int>> graph;
//         vector<bool> visited(n,true);
//         vector<int> cur(1,0);
//         ans=0;
//         while(scanf("%d %d",&a,&b),a||b){
//             graph[a-1].insert(b-1);
//             graph[b-1].insert(a-1);
//         }
//         printf("CASE %d:\n",tc++);
//         for(auto a : visited)
//             cout<<a<<' ';
//         cout<<'\n',
//         prune(n-1,graph,visited);
//         for(auto a : visited)
//             cout<<a<<' ';
//         cout<<'\n';
//         // if(!visited[0]) {
//         //     visited[0] = true;
//         //     dfs(0,graph,visited,cur);
//         // }
//         printf("There are %d routes from the firestation to streetcorner %d.\n",ans,n);
//     }
// }