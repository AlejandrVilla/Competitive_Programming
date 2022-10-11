#include <vector>
#include <iostream>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpi vector<vpii>
using namespace std;

int n,m;
vvpi M;
vvpi MT;
string sl = "\n ";

void print(vvpi& M)
{
    for(int i=0 ; i<M.size() ; ++i)
    {
        for(int j=0 ; j<M[i].size() ; ++j)
            cout<<'('<<M[i][j].first<<", "<<M[i][j].second<<") ";
        cout<<'\n';
    }
}

void solve()
{
    while(cin>>n>>m)
    {
        MT.resize(m);
        for(int i=0 ; i<n ; ++i)
        {
            vpii row;               // una fila
            int n_ind;cin>>n_ind;   // cant de indices
            for(int j=0 ; j<n_ind ; ++j)
            {
                int k;cin>>k;
                row.push_back(make_pair(k,0));      // indice de columna, dato
            }
            M.push_back(row);
            for(int j=0 ; j<n_ind ; ++j)
            {
                cin>>M[i][j].second;
            }
        }

        for(int i=0 ; i<M.size() ; ++i)             // filas
            for(int j=0 ; j<M[i].size() ; ++j)      // columnas
                // columna -> fila, fila -> columna
                MT[M[i][j].first-1].push_back(make_pair(i+1, M[i][j].second));

        cout<<m<<' '<<n<<'\n';
        for(int i=0 ; i<MT.size() ; ++i)
        {
            cout<<MT[i].size();         // tamanio
            if(MT[i].size())
                cout<<' ';
            else
                cout<<'\n';
            for(int j=0 ; j<MT[i].size() ; ++j)
            {
                cout<<MT[i][j].first;   // indices
                if(j+1!=MT[i].size())
                    cout<<' ';
                // else
                    // cout<<' ';
            }
            cout<<'\n';
            for(int j=0 ; j<MT[i].size() ; ++j)
            {
                cout<<MT[i][j].second;      // valor
                if(j+1!=MT[i].size())
                    cout<<' ';
                // else
                //     cout<<' ';
            }
            if(MT[i].size()!=0)
                cout<<'\n';
        }
        // print(M);
        // print(MT);
        M.clear();
        MT.clear();
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
