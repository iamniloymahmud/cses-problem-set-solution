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
    int n,k;
    cin >> n >> k;
    vector<int> ara(n),nexter;
    map<int,int> counter;
    tr(i,ara){
        cin >> i;
        counter[i]++;
    }
    nexter = ara;
    sort(all(ara));
    int a = -1,b = -1;
    for(int i = 0; i < n; ++i){
        if(binary_search(all(ara),k-nexter[i])){
            if(k-nexter[i] == nexter[i]){
                if(counter[nexter[i]] > 1){
                    a = i;
                    b = nexter[i];
                    break;
                }
            }else{
                a = i;
                b = k-nexter[i];
                break;
            }
        }
    }
    if(a != -1 and b != -1){
        cout << a+1 << " ";
        for(int i = 0; i < n; ++i){
            if(b == nexter[i] and i != a){
                cout << i+1 << endl;
                break;
            }
        }
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
