#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
 
//NILOY MAHMUD, KUET BME'18
 
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <iomanip>
#include <bitset>
 
 
using namespace std;
 
 
#define all(c) c.begin(),c.end()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(__gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define rep(i,s,n) for(int i = s; i < n; ++i)
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout(x) freopen(x, "w", stdout)
#define filein(x) freopen(x, "r",stdin)
#define error(x) freopen(x,"w",stderr)
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define inf 1<<30
#define linf 1<<60;
#define INF 1e9
#define mod 1000000007
#define pi acos(-1.)
#define gap " "
#define gapn " \n"
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
 
ostream & operator << (ostream & os, pair<int,int> a)
{
    return os << a.first << " " << a.second;
}
 
 
int x4[] = {0,1,0,-1};
int y4[] = {1,0,-1,0};
char m4[] = {'R', 'D', 'L', 'U'};


void bfs(vector<vector<int> > & edge, int n)
{
    vector<int> dis(n+1,-1);
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    vector<int> path(n+1, 0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        int d = dis[u];
        tr(i,edge[u]){
            if(dis[i] == -1){
                dis[i] = dis[u]+1;
                path[i] = u;
                q.push(i);
            }
        }
    }
    if(dis[n] == -1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        int a = path[n];
        vector<int> ara;
        ara.push_back(n);
        while(dis[a] != 0){
            ara.push_back(a);
            a = path[a];
        }
        ara.push_back(1);
        cout << ara.size() << endl;
        rtr(i,ara){
            cout << *i << gap;
        }
        cout << endl;
    }
}
int main()
{
    sync();
    int n,m;
    cin >> n >> m;
    vector<vector<int> > edge(n+1);
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    bfs(edge,n);
    return 0;
}
