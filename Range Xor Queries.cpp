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

int sum(int idx, vector<int> & ara)
{
    int summer = 0;
    while(idx > 0){
        summer^=ara[idx];
        idx-=(idx&-idx);
    }
    return summer;
}

void update(int idx, int n, int x, vector<int> & ara)
{
    while(idx <= n){
        ara[idx]^=x;
        idx+=(idx&-idx);
    }
}


int main()
{
    sync();
    int n,q;
    cin >> n >> q;
    vector<int> ara(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> ara[i];
    }
    vector<int> final(n+1);
    //BIT implementation 
    for(int i = 1; i <= n; ++i){
        update(i,n,ara[i],final);
    }
    int x,y;
    for(int i = 0; i < q; ++i){
        cin >> x >> y;
        int a = sum(y,final);
        if(x > 1){
            int b = sum(x-1,final);
            cout << (a^b) << endl;
        }else{
            cout << a << endl;
        }
    }
    return 0;
}
