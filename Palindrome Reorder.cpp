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
    string x;
    cin >> x;
    vector<int> ara(26,0);
    tr(i,x){
        int a = i - 'A';
        ara[a]++;
    }
    int odd = count_if(all(ara),[](int i){return i%2;});
    if(odd > 1){
        cout << "NO SOLUTION" << endl;
    }else if(odd == 1){
        int x;
        char ch;
        for(int i = 0; i < 26; ++i){
            if(ara[i] and iseven(ara[i])){
                char a = 'A' + i;
                ara[i]/=2;
                for(int j = 0; j < ara[i]; ++j){
                    cout << a;
                }
            }else if(isodd(ara[i])){
                x = ara[i];
                ara[i] = 0;
                ch = 'A'+i;
            }
        }
        for(int i = 0; i < x; ++i){
            cout << ch;
        }
        for(int i = 25; i >= 0; --i){
            if(ara[i]){
                char a = 'A' + i;
                for(int j = 0; j < ara[i]; ++j){
                    cout << a;
                }
            }
        }
        cout << endl;
    }else{
        for(int i = 0; i < 26; ++i){
            if(ara[i]){
                ara[i]/=2;
                char a = i + 'A';
                for(int j = 0; j < ara[i]; ++j){
                    cout << a;
                }
            }
        }
        for(int i = 25; i >= 0; --i){
            if(ara[i]){
                char a = i + 'A';
                for(int j = 0; j < ara[i]; ++j){
                    cout << a;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
