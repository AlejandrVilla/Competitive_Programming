#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#define sui stack<unsigned int>
#define sc stack<char>
#define AND(a,b) (a)&(b)
#define OR(a,b) (a)|(b)
#define NOT(a) ~(a)
#define IMPL(a,b) OR(NOT(a),(b))
#define BIC(a,b) AND(IMPL(a,b),IMPL(b,a))
using namespace std;

unsigned int p=2863311530;  // 10101010101010101010101010101010 
unsigned int q=3435973836;  // 11001100110011001100110011001100 
unsigned int r=4042322160;  // 11110000111100001111000011110000 
unsigned int s=4278255360;  // 11111111000000001111111100000000 
unsigned int t=4294901760;  // 11111111111111110000000000000000 

void toBinary( unsigned int num )
{
    string numBit;
    while(num!=0){
        numBit+=to_string(num%2);
        num/=2;
    }
    reverse(numBit.begin(),numBit.end());
    string ceros(32 - numBit.size(), '0');
    cout << ceros + numBit << '\n';
}

void solve()
{
    string cadena;
    while(cin>>cadena && cadena!="0")
    {
        sc operadores;
        sui bits;
        unsigned int res;
        for(int i=cadena.size()-1 ; i>=0 ; --i)        // K=AND, A=OR, N=NOT, C=IMPL, E=BIC
        {
            if(islower(cadena[i]))
            {
                if(cadena[i]=='p')bits.push(p);
                else if(cadena[i]=='q')bits.push(q);
                else if(cadena[i]=='r')bits.push(r);
                else if(cadena[i]=='s')bits.push(s);
                else if(cadena[i]=='t')bits.push(t);
            }
            else if(isupper(cadena[i]))
            {
                unsigned int a,b;
                if(cadena[i]=='K')
                {
                    a=bits.top();
                    bits.pop();
                    b=bits.top();
                    bits.pop();
                    bits.push(AND(a,b));
                }
                else if(cadena[i]=='A')
                {
                    a=bits.top();
                    bits.pop();
                    b=bits.top();
                    bits.pop();
                    bits.push(OR(a,b));
                }
                else if(cadena[i]=='C')
                {
                    a=bits.top();
                    bits.pop();
                    b=bits.top();
                    bits.pop();
                    bits.push(IMPL(a,b));
                }
                else if(cadena[i]=='E')
                {
                    a=bits.top();
                    bits.pop();
                    b=bits.top();
                    bits.pop();
                    bits.push(BIC(a,b));
                }
                else if(cadena[i]=='N')
                {
                    a=bits.top();
                    bits.pop();
                    bits.push(NOT(a));
                }
            }
        }
        res=bits.top();
        // cout<<res<<'\n';
        // toBinary(res);
        if(res==UINT_MAX)
            cout<<"tautology\n";
        else
            cout<<"not\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    solve();
}