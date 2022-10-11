#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

bool fn2(tuple<int,int,int>& a, tuple<int,int,int>& b)
{
    if(get<1>(a) > get<1>(b))
        return 1;
    else if(get<1>(a) == get<1>(b))
    {
        if(get<2>(a) < get<2>(b))
            return 1;
        else if(get<2>(a) == get<2>(b))
            if(get<0>(a) < get<0>(b))
                return 1;
    }
    return 0;
}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

void solve()
{
    int n;cin>>n;
    cin.ignore();
    cin.ignore();
    while(n--)
    {
        map<int, int> solves;           // team, solves
        map<int, int> time_acept;       // team, time
        map<int, map<int,int>> pena;    // team, problema, can
        map<int, map<int,bool>> use;    // team, problema, resuelto
        string submission;
        while(getline(cin,submission) && submission.size() != 0)
        {
            int team, problem, time;
            string team_, problem_, time_, state;
            stringstream linea(submission);
            getline(linea,team_,' ');
            getline(linea,problem_,' ');
            getline(linea,time_,' ');
            getline(linea,state,' ');
            team = stoi(team_);
            problem = stoi(problem_);
            time = stoi(time_);

            if( state == "C" && use[team][problem] == 0)
            {
                time_acept[team] += time + 20*pena[team][problem];
                solves[team]++;
                use[team][problem] = 1;
            }
            else if (state == "I")
            {
                pena[team][problem]++;
                time_acept[team] += 0;
                solves[team] += 0;
            }
            else
            {
                pena[team][problem] += 0;
                time_acept[team] += 0;
                solves[team] += 0;
            }
        }
        vector<tuple<int,int,int>> res; // team, resueltos, penalizacion
        for(auto it = solves.begin(); it!=solves.end() ; ++it)
        {
            //  team, resueltos, penalizacion
            res.push_back(make_tuple(it->first, solves[it->first], time_acept[it->first]));
        }
        sort(res.begin(), res.end(), fn2);
        for(auto a:res)
            cout<<get<0>(a)<<' '<<get<1>(a)<<' '<<get<2>(a)<<'\n';
        if(n!=0)
            cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}