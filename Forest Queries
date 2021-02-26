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
#define INF 1e9
#define mod 1000000007
#define pi acos(-1.)
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))
 
 
int x4[] = {0,1,0,-1};
int y4[] = {1,0,-1,0};
 
void precalculate(vector<vector<int> > & ara, vector<vector<int> > & matrix, int n)
{
    for(int i = 0; i < n; ++i){
        ara[0][i] = matrix[0][i];
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            ara[i][j] = matrix[i][j]+ara[i-1][j];
        }
    }
    for(int i = 0; i  < n; ++i){
        for(int j = 1; j < n; ++j){
            ara[i][j]+=ara[i][j-1];
        }
    }
}
 
int sum(int a,int b, int x, int y,vector<vector<int> > & ara)
{
    a--;
    b--;
    x--;
    y--;
    int sum = ara[x][y];
    if(b > 0){
        sum-=ara[x][b-1];
    }
    if(a > 0){
        sum-=ara[a-1][y];
    }
    if(a > 0 and b > 0){
        sum+=ara[a-1][b-1];
    }
    return sum;
}
 
 
int main()
{
    sync();
    int n,q;
    cin >> n >> q;
    vector<string> forest(n);
    tr(i,forest){
        cin >> i;
    }
    vector<vector<int> > ara(n,vector<int>(n,0));
    vector<vector<int> > final(n,vector<int>(n,0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(forest[i][j] == '*'){
                ara[i][j] = 1;
            }
        }
    }
    precalculate(final,ara,n); //prefix sum array of 2D grid
    int a,b,x,y;
    for(int i = 0; i < q; ++i){
        cin >> a >> b >> x >> y;
        cout << sum(a,b,x,y,final) << endl;
    }
    return 0;
}
