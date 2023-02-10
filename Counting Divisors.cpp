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
 
vector<int> prime;
 
void sieve()
{
    int n = 1e6+1;
    vector<int> isprime(n,0);
    for(int i = 4; i < n; i+=2){
        isprime[i] = 1;
    }
    prime.push_back(2);
    int x = sqrt(n);
    for(int i = 3; i < n; i+=2){
        if(isprime[i] == 0){
            prime.push_back(i);
            if(i <= x){
                for(int j = sqr(i); j < n; j+=(i*2)){
                    isprime[j] = 1;
                }
            }
        }
    }
}
 
int counter(int n){
    int i = 0;
    int result = 1;
    int square = sqrt(n);
    int a = prime.size();
    while(i < a and prime[i] <= square){
        if(n%prime[i] == 0){
            int x = 0;
            while(n%prime[i] == 0){
                n/=prime[i];
                x++;
            }
            square = sqrt(n);
            result*=(x+1);
        }
        i++;
    }
    if(n > 1){
        result*=2;
    }
    return result;
}
 
int main()
{
    sync();
    int t;
    cin >> t;
    int n;
    sieve();
    while(t--){
        cin >> n;
        cout << counter(n) << endl;
    }
    return 0;
}
