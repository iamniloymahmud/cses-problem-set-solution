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
 
 
void bfs(vector<string> & ara, int n, int m)
{
    int sx,sy,ex,ey;
    rep(i,0,n){
        rep(j,0,m){
            if(ara[i][j] == 'A'){
                sx = i;
                sy = j;
            }
            if(ara[i][j] == 'B'){
                ex = i;
                ey = j;
            }
        }
    }
    vector<vector<char> > mapper(n,vector<char>(m,'x'));
    map <pair<int,int>, pair<int,int> > pos;
    queue <pair<int,int> > q;
    q.push({sx,sy});
    mapper[sx][sy] = 'S';
    while(!q.empty()){
        pii a = q.front();
        q.pop();
        rep(i,0,4){
            int x = a.first+x4[i];
            int y = a.second+y4[i];
            if(valid(x,y,n,m) and (ara[x][y] == '.' or ara[x][y] == 'B')){
                ara[x][y] = '#';
                mapper[x][y] = m4[i];
                pos[{x,y}] = a;
                q.push({x,y});
            }
        }
        if(ara[ex][ey] == '#')break;
    }
    string path = "";
    if(ara[ex][ey] == '#'){
        pair<int,int> c = {ex,ey};
        while(mapper[c.first][c.second] != 'S'){
            path+=mapper[c.first][c.second];
            c = pos[c];
        }
        reverse(all(path));
        cout << "YES" << endl;
        cout << path.size() << endl;
        cout << path << endl;
    }else{
        cout << "NO" << endl;
    }
}
 
int main()
{
    sync();
    int n,m;
    cin >> n >> m;
    vector<string> ara(n);
    tr(i,ara){
        cin >> i;
    }
    bfs(ara,n,m);
    return 0;
}
