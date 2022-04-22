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
#define linf 1<<60;
#define INF 1e9
#define mod 1000000007
#define pi acos(-1.)
#define gap " "
#define gapn " \n"
#define valid(x,y,row,col) (((x) >= 0 and (x) < row) and ((y) >= 0 and (y) < col))
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define timer(d) for(long blockTime=NULL;(blockTime==NULL?(blockTime=clock())!=NULL:false); debug("%s:%.4fs",d,(double)(clock()-blockTime)/CLOCKS_PER_SEC))
 
ostream & operator << (ostream & os, pair<int,int> a)
{
    return os << a.first << " " << a.second;
}
 
int x4[] = {0,1,0,-1};
int y4[] = {1,0,-1,0};
 
void make_tree(vector<pair<int,int> > & ara, vector<int> & input, int b, int e, int node)
{
    if(b == e){
        ara[node].first = input[b];
        ara[node].second = 1;
        return;
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
    make_tree(ara,input,b,mid,left);
    make_tree(ara,input,mid+1,e,right);
 
    ara[node].second = ara[left].second + ara[right].second;
}
 
pair<int,int> query(vector<pair<int,int> > & ara, int b, int e, int node, int q)
{
    if(b == e and q == 1) {
        return {ara[node].first, b};
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
    if(ara[left].second >= q){
        return query(ara,b,mid,left,q);
    }else{
        return query(ara,mid+1,e,right,q-ara[left].second);
    }
}
 
void update(vector<pair<int,int> > & ara, int b, int e, int node,  int i)
{
    if(b > i or e < i){
        return;
    }
    if(b >= i and e <= i){
        ara[node].second = 0;
        return;
    }
    int left = node << 1;
    int right = left+1;
    int mid = (b+e) >> 1;
    update(ara,b,mid,left,i);
    update(ara,mid+1,e,right,i);
 
    ara[node].second = ara[left].second + ara[right].second;
}
 
int main()
{
    sync();
    int n;
    cin >> n;
    vector<int> ara(n+1),pos(n);
    for(int i = 1; i <= n; ++i){
        cin >> ara[i];
    }
    tr(i,pos){
        cin >> i;
    }
    vector<pair<int,int> > tree(4*n, {0,0});
 
    make_tree(tree,ara,1,n,1);
    tr(i,pos){
        auto x = query(tree,1,n,1,i);
        cout << x.first << gap;
        update(tree,1,n,1,x.second);
    }
    return 0;
}
