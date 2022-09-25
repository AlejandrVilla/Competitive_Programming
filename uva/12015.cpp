#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;cin>>n;
    for(int j=1;j<=n;j++){
        int max=0;
        vector<pair<string,int>> pages;
        for(int i=0;i<10;i++){
            string page;cin>>page;
            int pri;cin>>pri;
            pair<string,int> caso;
            caso.first=page;
            caso.second=pri;
            pages.push_back(caso);
            if (pri>max)
                max=pri;
        }
        cout<<"Case #"<<j<<":\n";
        for(int i=0;i<10;i++){
            if (pages[i].second==max)
                cout<<pages[i].first<<'\n';
        }
    }
}