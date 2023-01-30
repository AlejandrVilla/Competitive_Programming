#include <iostream>
#include <map>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vc>
#define mii map<int,int>
#define loop(a,b,c) for(a=b ; a<c ; ++a)
using namespace std;

int f_ini, c_ini;

bool ataca(int f_1, int c_1, int f_2, int c_2)
{
    if(f_1==f_2) return 1;
    if(abs(f_1-f_2) == abs(c_1-c_2)) return 1;
    return 0;
}

bool ataca(vc& table, int c)
{
    int i;
    loop(i,0,c)
        if(ataca(table[i],i,table[c],c)) return 1;
    return 0;
}

void solution(vvc& res)
{
    cout<<"SOLN       COLUMN\n";
    cout<<" #      1 2 3 4 5 6 7 8\n\n";
    int i,n=res.size();
    loop(i,0,n)
    {
        if(i<9)
            cout<<" ";
        cout<<i+1<<"      ";
        int j;
        loop(j,0,8)
        {
            cout<<res[i][j]+1;
            if(j!=7) cout<<' ';
        }
        cout<<'\n';
    }
}

void solve()
{
    cin>>f_ini>>c_ini;
    // cout<<f_ini<<" "<<c_ini<<'\n';
    int a,b,c,d,e,f,g,h;
    vc table(8);
    int cont=0;
    vvc res;
    loop(a,0,8)
    {
        table[0] = char(a);
        loop(b,0,8)
        {
            table[1] = char(b);
            if(ataca(table,1)) continue;
            loop(c,0,8)
            {
                table[2] = char(c);
                    if(ataca(table,2)) continue;
                loop(d,0,8)
                {
                    table[3] = char(d);
                        if(ataca(table,3)) continue;
                    loop(e,0,8)
                    {
                        table[4] = char(e);
                            if(ataca(table,4)) continue;
                        loop(f,0,8)
                        {
                            table[5] = char(f);
                                if(ataca(table,5)) continue;
                            loop(g,0,8)
                            {
                                table[6] = char(g);
                                    if(ataca(table,6)) continue;
                                loop(h,0,8)
                                {
                                    table[7] = char(h);
                                        if(ataca(table,7)) continue;
                                    if(table[c_ini-1]==f_ini-1) 
                                        res.push_back(table);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    solution(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<'\n';
    }
}