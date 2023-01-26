#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

enum{N=1,E=2,S=3,W=4,F=0,borde=5};
        // N,E,S,W
vi ud = {1,0,-1,0};
vi lr = {0,1,0,-1};
vvi matrix;
int n,m;

void solve()
{
    int x,y;
    char ort;
    while(cin>>x>>y>>ort)
    {
        string inst;cin>>inst;
        bool fell=0;
        int dir;
        if(ort=='N')
            dir=0;
        else if(ort=='E')
            dir=1;
        else if(ort=='S')
            dir=2;
        else
            dir=3;
        for(int i=0 ; i<inst.size() ; ++i)
        {
            if(inst[i]=='F')        // front
            {
                if(y+ud[dir]<0 || y+ud[dir]>m)
                {
                    if(matrix[x][y]==F) // libre
                    {
                        matrix[x][y]=borde; // marca no se puede ir al S
                        fell=1;
                        break;
                    }
                }
                else if(x+lr[dir]<0 || x+lr[dir]>n)
                {
                    if(matrix[x][y]==F) // libre
                    {
                        matrix[x][y]=borde; // marca no se puede ir al S
                        fell=1;
                        break;
                    }
                }
                else
                {
                    x+=lr[dir];
                    y+=ud[dir];
                }
            }
            else if(inst[i]=='R')       // right
                dir = (dir==3)? 0 : dir+1;
            else if(inst[i]=='L')       // left
                dir = (dir==0)? 3 : dir-1;
        }
        cout<<x<<" "<<y<<" ";
        dir++;
        if(dir==N)
            cout<<"N";
        else if(dir==E)
            cout<<"E";
        else if(dir==S)
            cout<<"S";
        else
            cout<<"W";
        if(fell)
            cout<<" LOST";
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    matrix.assign(n+1,vi(m+1,F));
    solve();
}