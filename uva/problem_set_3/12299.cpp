#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#define vi vector<int>
#define l(i) (((i)<<1)+1)
#define r(i) (((i)<<1)+2)
using namespace std;

int large=100000;
vi arr(large,0);
vi st(4*large,0);
int n,q;

void print(vi& A)
{
    for(int i=0 ; i<n ; ++i)
        cout<<A[i]<<' ';
    cout<<'\n';
}

void built(int st_i, int a, int b)
{
    if(a==b)
    {
        st[st_i] = arr[a];
        return;
    }
    int m = (a+b)/2;
    built(l(st_i),a,m);
    built(r(st_i),m+1,b);
    st[st_i] = min(st[l(st_i)], st[r(st_i)]);
}

int rmq(int st_i, int st_l, int st_r, int a, int b)
{
    if(a<=st_l && st_r<=b)
        return st[st_i];
    if(st_r<a || b<st_l)
        return INT32_MAX; 
    int m=(st_l+st_r)/2;
    return min(rmq(l(st_i),st_l,m,a,b) ,rmq(r(st_i),m+1,st_r,a,b));   
}

void update(int st_i, int st_l, int st_r, int i, int v)
{
    if(i<st_l || st_r<i)
        return;
    if(st_l == st_r)
    {
        st[st_i] = v;
        return;
    }
    int m=(st_l+st_r)/2;
    update(l(st_i),st_l,m,i,v);
    update(r(st_i),m+1,st_r,i,v);
    st[st_i] = min(st[l(st_i)],st[r(st_i)]);
}

void solve()
{
    cin>>n>>q;
    for(int i=0 ; i<n ; ++i)
        cin>>arr[i];
    built(0,0,n-1);
    while(q--)
    {
        string query;cin>>query;
        string query2=query.substr(6,query.size());
        stringstream linea(query2);
        string num;
        if(query[0]=='q')
        {
            int a,b;
            getline(linea,num,',');
            a=stoi(num);
            getline(linea,num,',');
            b=stoi(num);
            cout<<rmq(0,0,n-1,a-1,b-1)<<'\n';
        }
        else if(query[0]=='s')
        {
            getline(linea,num,',');
            int j = stoi(num)-1;
            int tmp = arr[j];
            while(getline(linea,num,','))
            {
                int i=stoi(num)-1;
                update(0,0,n-1,j,arr[i]);
                arr[j] = arr[i];
                j=i;
            }
            update(0,0,n-1,j,tmp);
            arr[j] = tmp;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
}