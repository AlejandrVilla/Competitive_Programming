#include <iostream>
using namespace std;
int main(){
    int v,n,s;
    while( scanf( "%d %d", &v, &n ) != EOF ){
        s = 2*v*n;
        printf( "%d\n" , s );
    }   
    return 0;
}