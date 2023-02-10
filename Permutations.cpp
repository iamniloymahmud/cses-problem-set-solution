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
 
 
using namespace std;
 
 
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define allb(c) c.begin(),c.end(),c.begin()
#define gcd(a,b) __gcd(abs(a),abs(b))
#define lcm(a,b) (((a)/(gcd(a,b)))*(b))
#define isodd(a) ((a)&1)
#define iseven(a) !((a)&1)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp map<string,int>
#define mii map<int,int>
#define tr(it,c) for(auto & it : (c))
#define rtr(it,c) for(auto it = (c).rbegin(); it != (c).rend(); it++)
#define ll long long
#define endl "\n"
#define abs(x) (((x) < 0) ? -(x) : (x))
#define swp(a,b) (a = a^b,b = a^b,a = a^b)
#define clr(x,y) memset((x),(y),sizeof(x))
#define popcount(x) __builtin_popcount(x)
#define fileout() freopen("output.txt", "w", stdout)
#define filein() freopen("input.txt", "r",stdin)
#define error() freopen("error.txt","w",stderr)
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define inf 1<<30
#define linf 1<<62
#define mod 1000000007
#define pi acos(-1.)
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))
 
int x4[] = {0,0,1,-1};
int y4[] = {1,-1,0,0};
 
int main()
{
    sync();
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION" << endl;
    }else{
        for(int i = 2; i <= n; i+=2){
            cout << i << " ";
        }
        for(int i = 1; i <= n; i+=2){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
