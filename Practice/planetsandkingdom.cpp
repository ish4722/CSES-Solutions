#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;


mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define ez ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define f(i,a,b) for(int i=a; i<b; i++)
#define getv(v, n) vector<int> v(n); f(i,0,n) cin >> v[i];

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector<int> parent,sz;
int par(int u){
    if(u==parent[u]) return u;
    return parent[u]=par(parent[u]);
}
void unite(int a,int b){
    int u=par(a);
    int v=par(b);
    if(u==v) return;
    if(sz[u]<sz[v]) swap(u,v);
    parent[v]=u;
    sz[u]+=sz[v];
}

// void solve() {
//     int n,m;
//     cin>>n>>m;

//     parent.resize(n);
//     f(i,0,n) parent[i]=i;
//     sz.assign(n,1);

//     f(i,0,m){
//         int a,b;
//         cin>>a>>b;
//         unite(a-1,b-1);
//     }

//     map<int,int> mp;
//     int cnt=0;

//     for(int i=0;i<n;i++){
//         int root=par(i);

//         if(!mp.count(root))
//             mp[root]=++cnt;
//     }

//     cout<<cnt<<endl;

//     for(int i=0;i<n;i++){
//         cout<<mp[par(i)]<<" ";
//     }
//     cout<<endl;
// }

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}