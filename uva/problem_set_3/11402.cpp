#include <vector>
#include <iostream>
#define si short int
#define vsi vector<si>
#define vi vector<int>
#define l(i) ((i)<<1)+1
#define r(i) ((i)<<1)+2
using namespace std;

int large = 1024000;
vsi arr(large,0);
vi st(4*large,0);
vsi lazy(4*large,-1);
int N;

void print(vi& A)
{
    for(int i=0 ; i<4*N ; ++i)
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
    built(l(st_i), a, m);
    built(r(st_i), m+1, b);
    st[st_i] = st[l(st_i)] + st[r(st_i)];
}


int rsq(int st_i, int st_l, int st_r, int a, int b)
{
    if(lazy[st_i]==0 || lazy[st_i]==1)
    {
        st[st_i] = (st_r-st_l+1)*lazy[st_i];
        if(st_l!=st_r)
        {
            lazy[l(st_i)] = lazy[st_i];
            lazy[r(st_i)] = lazy[st_i];
        }
        lazy[st_i] = -1;
    }
    else if(lazy[st_i]==2)
    {
        st[st_i] = (st_r-st_l+1) - st[st_i];
        if(st_l!=st_r)
        {
            if(lazy[l(st_i)]==0)
                lazy[l(st_i)]=1;
            else if(lazy[l(st_i)]==1)
                lazy[l(st_i)]=0;
            if(lazy[r(st_i)]==0)
                lazy[r(st_i)]=1;
            else if(lazy[r(st_i)]==1)
                lazy[r(st_i)]=0;
            if(lazy[l(st_i)]==2)
                lazy[l(st_i)]=-1;
            else if(lazy[l(st_i)]==-1)
                lazy[l(st_i)] = lazy[st_i];
            if(lazy[r(st_i)]==2)
                lazy[r(st_i)]=-1;
            else if(lazy[r(st_i)]==-1)
                lazy[r(st_i)] = lazy[st_i];
        }
        lazy[st_i] = -1;
    }
    if(a<=st_l && st_r<=b)
        return st[st_i];
    if(b<st_l || st_r<a)
        return 0;
    int m = (st_l+st_r)/2;
    return rsq(l(st_i), st_l, m, a, b) + rsq(r(st_i), m+1, st_r, a, b);
}


void update(int st_i, int st_l, int st_r, int i, int j, int v)      // v = 0,1,2
{
    if(lazy[st_i]==0 || lazy[st_i]==1)
    {
        st[st_i] = (st_r-st_l+1)*lazy[st_i];
        if(st_l!=st_r)
        {
            lazy[l(st_i)] = lazy[st_i];
            lazy[r(st_i)] = lazy[st_i];
        }
        lazy[st_i] = -1;
    }
    else if(lazy[st_i]==2)
    {
        st[st_i] = (st_r-st_l+1) - st[st_i];
        if(st_l!=st_r)
        {
            if(lazy[l(st_i)]==0)
                lazy[l(st_i)]=1;
            else if(lazy[l(st_i)]==1)
                lazy[l(st_i)]=0;
            if(lazy[r(st_i)]==0)
                lazy[r(st_i)]=1;
            else if(lazy[r(st_i)]==1)
                lazy[r(st_i)]=0;
            if(lazy[l(st_i)]==2)
                lazy[l(st_i)]=-1;
            else if(lazy[l(st_i)]==-1)
                lazy[l(st_i)] = lazy[st_i];
            if(lazy[r(st_i)]==2)
                lazy[r(st_i)]=-1;
            else if(lazy[r(st_i)]==-1)
                lazy[r(st_i)] = lazy[st_i];
        }
        lazy[st_i] = -1;
    }
    if(j<st_l || st_r<i)
        return;
    if(i<=st_l && st_r<=j)
    {
        if(v==0 || v==1)
        {
            st[st_i] = (st_r-st_l+1)*v;
            if(st_l!=st_r)
            {
                lazy[l(st_i)] = v;
                lazy[r(st_i)] = v;
            }
            return;
        }
        else if(v==2)
        {
            st[st_i] = (st_r-st_l+1) - st[st_i];
            if(st_l!=st_r)
            {
                if(lazy[l(st_i)]==0)
                    lazy[l(st_i)]=1;
                else if(lazy[l(st_i)]==1)
                    lazy[l(st_i)]=0;
                if(lazy[r(st_i)]==0)
                    lazy[r(st_i)]=1;
                else if(lazy[r(st_i)]==1)
                    lazy[r(st_i)]=0;
                if(lazy[l(st_i)]==2)
                    lazy[l(st_i)]=-1;
                else if(lazy[l(st_i)]==-1)
                    lazy[l(st_i)] = v;
                if(lazy[r(st_i)]==2)
                    lazy[r(st_i)]=-1;
                else if(lazy[r(st_i)]==-1)
                    lazy[r(st_i)] = v;
            }
            return;
        }
    }
    int m = (st_l+st_r)/2;
    update(l(st_i), st_l, m, i, j, v);
    update(r(st_i), m+1, st_r, i, j, v);
    st[st_i] = st[l(st_i)] + st[r(st_i)];
}

void solve()
{
    int t;cin>>t;
    string res;
    while(t--)
    {
        int m;cin>>m;
        string pirates;cin>>pirates;
        while(m--)
            res+=pirates;
    }
    // cout<<res<<'\n';
    N = res.size();
    for(int i=0 ; i<N ; ++i)
    {
        arr[i] = int(res[i] - '0');
        lazy[4*i] = -1;
        lazy[4*i+1] = -1;
        lazy[4*i+2] = -1;
        lazy[4*i+3] = -1;    
        st[4*i] = 0;
        st[4*i+1] = 0;
        st[4*i+2] = 0;
        st[4*i+3] = 0;
    }
    built(0,0,N-1);
    int q;cin>>q;
    int query=1;
    while(q--)      // 0 babary, 1 bucanner
    {
        // print(st);
        char op;cin>>op;
        if(op == 'F')           // to bucanner (1)
        {
            int a,b;cin>>a>>b;
            update(0,0,N-1,a,b,1);
        }
        else if(op == 'E')      // to barbary (0)
        {
            int a,b;cin>>a>>b;
            update(0,0,N-1,a,b,0);
        }
        else if(op == 'I')      // inverse
        {
            int a,b;cin>>a>>b;
            update(0,0,N-1,a,b,2);
        }   
        else if(op == 'S')      // how many bucanners
        {
            int a,b;cin>>a>>b;
            cout<<"Q"<<query++<<": "<<rsq(0,0,N-1,a,b)<<'\n';
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
    int t;cin>>t;
    for(int i=1 ; i<=t ; ++i)
    {
        cout<<"Case "<<i<<":\n";
        solve();
    }
}