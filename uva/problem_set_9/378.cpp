#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <numeric>      // accumulate
#include <fstream>
#define loop(a,b,c) for(int a=b ; a<c ; ++a)
#define vstr vector<string>
#define ll long long int
#define tiii tuple<int,int,int>
#define tdii tuple<double,int,int>
#define pii pair<int,int>
#define vtiii vector<tiii>
#define vtdii vector<tdii>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define qi queue<int>
#define pqpii priority_queue<pii,vpii,greater<pair<int,int>>>
#define mimii map<int,map<int,int>>
#define mii map<int,int>
#define si set<int>
#define sc set<char>
#define sll set<ll>
#define msi multiset<int>
#define EPS 1e-9
#define EQ(a,b) fabs(a-b)<=EPS  // igualar numeros reales
#define MAX 1000002
using namespace std;

struct point
{
    double x,y;
    point(){x=y=0.0;}
    point(double _x, double _y):x(_x),y(_y){}
    bool operator<(point other) const
    {
        if(fabs(x-other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator==(const point& other) const
    {
        return (fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS);
    }
};

struct line     // ax+by+c=0
{
    double a,b,c;
    bool operator==(const line& other) const
    {
        return (fabs(a-other.a) < EPS) 
            && (fabs(b-other.b) < EPS) 
            && (fabs(c-other.c) < EPS);
    }
};

void pointsToLine(point& p1, point& p2, line& L)    // ax + by + c = 0
{
    if(fabs(p1.x-p2.x) < EPS)
    {
        L.a=1.0;
        L.b=0.0;
        L.c=-p1.x;  // 0 = -x+5 -> x=5
        // L={1.0,0.0,-p1.x};
    }
    else
    {
        L.a=-(double)(p1.y-p2.y) / (p1.x-p2.x);
        L.b=1.0;
        L.c=-(double)(L.a*p1.x)-p1.y;
        // L={, 1.0, -(double)(L.a*p1.x)-p1.y};
    }
}

bool areParallel(line l1, line l2)
{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2)
{
    return areParallel(l1,l2) && (fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point& p)
{
    if(areParallel(l1,l2)) return false;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if(fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

bool pointInLine(pair<point,point> pl, point& p)
{
    return (p.x>=min(pl.first.x,pl.second.x) && p.x<=max(pl.first.x,pl.second.x)) 
        && (p.y>=min(pl.first.y,pl.second.y) && p.y<=max(pl.first.y,pl.second.y));

}

void solve()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4);
    line L1,L2;
    pointsToLine(p1,p2,L1);
    pointsToLine(p3,p4,L2);
    point p;
    if(L1 == L2)
        cout<<"LINE\n";
    else if(areIntersect(L1,L2,p))
        cout<<"POINT "<<setprecision(2)<<fixed<<p.x<<" "<<p.y<<'\n';
    else
        cout<<"NONE\n";
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
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(t--)
        solve();
    cout<<"END OF OUTPUT\n";
}
