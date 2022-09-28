#include <iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int i=1;
    while(n--){
        int k;cin>>k;
        int max=0;
        while(k--){
            int num;cin>>num;
            max = num>max? num : max;
        }
        cout<<"Case "<<i<<": "<<max<<'\n';
        i++;
    }
}