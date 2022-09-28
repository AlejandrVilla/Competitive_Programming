#include <bits/stdc++.h>
#define vi vector<int>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define si set<int>
using namespace std;

/*

    1 represents B, F, P, or V
    2 represents C, G, J, K, Q, S, X,  or Z
    3 represents D or T
    4 represents L
    5 represents M or N
    6 represents R
*/

vvc letras={    {},
                {'B', 'F', 'P', 'V'},
                {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'},
                {'D', 'T'},
                {'L'},
                {'M', 'N'},
                {'R'}
            };

int getCode(char& c)
{
    for(int j=1 ; j<letras.size() ; ++j)
        if(find(letras[j].begin(), letras[j].end(), c) != letras[j].end())
            return j;
    return 0;
}

void solve()
{
    string in;
    while(cin>>in)
    {
        string res;
        int code = getCode(in[0]);
        if(code)
            res += char(code + '0');
        for(int i=1 ; i<in.size() ; ++i)
        {
            int code_c, code_p;
            code_c = getCode(in[i]);
            code_p = getCode(in[i-1]);
            if(code_c && code_c != code_p)
                res += char(code_c + '0');
        }
        cout<<res<<'\n';
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}