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


void dfs(vector<int> & ara, vector<vector<int> > & edges, int u, int k)
{
    if(ara[u] != -1){
        return;
    }
    ara[u] = k;
    tr(i,edges[u]){
        dfs(ara,edges,i,k);
    }
}

int main()
{
    sync();
    int n,m;
    cin >> n >> m;
    vector<vector<int> > edge(n+1);
    vector<int> ara(n+1, -1);
    ara[0] = -2;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int k = 0;
    int a = 1;
    while(a < n+1){
        dfs(ara,edge,a,k);
        while(a < n+1 and ara[a] != -1)a++;
        k++;
    }
    if(k == 1){
        cout << 0 << endl;
    }else{
        --k;
        cout << k << endl;
        vector<int> path(k+1, -1);
        rep(i,1,n+1){
            path[ara[i]] = i; 
        }
        rep(i,0,k){
            cout << path[i] << gap << path[i+1] << endl;
        }
        cout << endl;
    }
    return 0;
}
