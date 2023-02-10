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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> des(n),app(m);
    tr(i,des){
        cin >> i;
    }
    tr(i,app){
        cin >> i;
    }
    sort(all(app));
    sort(all(des));
 
    int j = 0;
    int counter = 0;
    for(int i = 0; i < n; ++i){
        ll a = des[i]-k;
        ll b = des[i]+k;
        while(j < m){
            if(app[j] >= a and app[j] <= b){
                counter++;
                j++;
                break;
            }else if(app[j] > b){
                break;
            }
            j++;
        }
    }
    cout << counter << endl;
    return 0;
}
