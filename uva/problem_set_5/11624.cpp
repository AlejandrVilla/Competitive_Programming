#include <iostream>
#include <vector>
#include <queue>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>    
#define vvi vector<vi>
#define qpii queue<pii>
#define vqpii vector<qpii>
#define vi vector<int>
using namespace std;

vs matrix;
vpii puntos_fire;
int R,C;
int J_i,J_j;
vvi res(1000,vi(1000));

vi pup = {-1,1,0,0};
vi plr = { 0,0,-1,1};

void game()
{
    vqpii F;
    qpii J;
    J.push({J_i,J_j});
    for(int i=0 ; i<puntos_fire.size() ; ++i)
    {
        qpii q;
        q.push({puntos_fire[i].first,puntos_fire[i].second});
        F.push_back(q);
    }
    while(!J.empty())
    {
        for(int l=0 ; l<F.size() ; ++l)
        {
            qpii q_aux;
            while(!F[l].empty())
            {
                int i=F[l].front().first;
                int j=F[l].front().second;
                F[l].pop();
                for(int k=0 ; k<4 ; ++k)
                {
                    if(i+pup[k]<0 || i+pup[k]>=R || j+plr[k]<0 || j+plr[k]>=C) continue;
                    if(matrix[i+pup[k]][j+plr[k]]=='#') continue;
                    if(matrix[i+pup[k]][j+plr[k]]!='F')
                    {
                        matrix[i+pup[k]][j+plr[k]]='F';
                        q_aux.push({i+pup[k],j+plr[k]});
                    }
                }
            }
            F[l] = q_aux;
        }
        qpii q_aux;
        while(!J.empty())
        {
            J_i = J.front().first;
            J_j = J.front().second;
            J.pop();
            for(int k=0 ; k<4 ; ++k)
            {
                if(J_i+pup[k]<0 || J_i+pup[k]>=R || J_j+plr[k]<0 || J_j+plr[k]>=C)
                {
                    cout<<res[J_i][J_j]+1<<'\n';
                    return;
                }
                else if(matrix[J_i+pup[k]][J_j+plr[k]]=='.')
                {
                    matrix[J_i+pup[k]][J_j+plr[k]]='J';
                    res[J_i+pup[k]][J_j+plr[k]]=res[J_i][J_j]+1;
                    q_aux.push({J_i+pup[k],J_j+plr[k]});
                }
            }
        }
        J=q_aux;
    }
    cout<<"IMPOSSIBLE\n";
}

void solve()
{
    cin>>R>>C;
    matrix.clear();
    puntos_fire.clear();
    matrix.resize(R);
    for(int i=0 ; i<R ; ++i)
        cin>>matrix[i];
    for(int i=0 ; i<R ; ++i)
        for(int j=0 ; j<C ; ++j)
        {
            if(matrix[i][j]=='J')
            {
                J_i = i;
                J_j = j;
                res[J_i][J_j]=0;
            }
            else if(matrix[i][j]=='F')
                puntos_fire.push_back({i,j});
        }
    game();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    while(t--)
        solve();
}
