#include <iostream>
#include <vector>
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
using namespace std;
vvi matrix;
vvi sum;
int n;

void solve()
{
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<n ; ++j)
            cin>>matrix[i][j];
    sum[0][0] = matrix[0][0];
    for(int f=1 ; f<n ; ++f)
        sum[f][0] = matrix[f][0] + sum[f-1][0];
    for(int c=1 ; c<n ; ++c)
        sum[0][c] = matrix[0][c] + sum[0][c-1];
    for(int f=1 ; f<n ; ++f)
        for(int c=1 ; c<n ; ++c)
            sum[f][c] = sum[f][c-1] + sum[f-1][c] - sum[f-1][c-1] + matrix[f][c];

    int summax = INT32_MIN;
    for(int ini_f=0 ; ini_f<n ; ++ini_f)        
    {
        for(int ini_c=0 ; ini_c<n ; ++ini_c)
        {
            for(int fin_f=ini_f ; fin_f<n ; ++fin_f)
            {
                for(int fin_c=ini_c ; fin_c<n ; ++fin_c)
                {
                    int sumtmp=0;
                    if(ini_f==0 && ini_c==0)
                        sumtmp=sum[fin_f][fin_c];
                    else if(ini_f==0 && ini_c!=0)
                        sumtmp=sum[fin_f][fin_c]-sum[fin_f][ini_c-1];
                    else if(ini_f!=0 && ini_c==0)
                        sumtmp=sum[fin_f][fin_c]-sum[ini_f-1][fin_c];
                    else if(ini_f!=0 && ini_c!=0)
                        sumtmp=sum[fin_f][fin_c]-sum[fin_f][ini_c-1]
                         -sum[ini_f-1][fin_c]+sum[ini_f-1][ini_c-1];
                    if(sumtmp>summax)
                        summax=sumtmp;
                }
            }
        }
    }
    cout<<summax<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    while(cin>>n)
    {
        matrix.assign(n,vi(n,0));
        sum.assign(n,vi(n,0));
        solve();
    }
}