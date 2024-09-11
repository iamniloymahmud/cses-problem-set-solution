#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>

//JAIED BIN MAHMUD, KUET BME'18

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
#define mod(a,b) (a-(a/b)*b)
#define sync() ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define pii pair<int,int>
#define pll pair<long long, long long>
#define rep(i,s,n) for(int i = s; i < n; ++i)
#define per(i,s,e) for(int i = s; i >= e; --i)
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
#define modulus 1000000007
#define mod(a,b) ((a)%b+b)%b
#define pi acos(-1.)
#define ncout(var,i,n) cout << var << " \n" [i == n-1];
#define gap " "
#define gapn " \n"
#define byte(num,bits) bitset<bits> (num)
#define valid(x,y,startrow,startcol,row,col) (((x) >= startrow and (x) < row) and ((y) >= startcol and (y) < col))

ostream & operator << (ostream & os, pair<int,int> a)
{
    return os << a.first << " " << a.second;
}


int x4[] = {0,1,0,-1};
int y4[] = {1,0,-1,0};

int knight_x[] = {-2,-1,1,2,2,1,-1,-2};
int knight_y[] = {1, 2, 2,1,-1,-2,-2,-1};

class CompareByParameter{
public:
    int para;
    CompareByParameter(int m){
        para = m;
    }
    bool operator () (int i){
        return i < para;
    }
};



int main()
{
    sync();
    string x;
    cin >> x;
    int n = x.size();
    int answer = 1;
    int temp = 1;
    rep(i,1,n) {
        if(x[i] == x[i-1])temp++;
        else temp = 1;
        answer = max(answer, temp);
    }

    cout << answer << endl;

    return 0;
}
