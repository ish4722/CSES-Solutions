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

// int ans(int i, int m,int cnt){
//     if(i==m){
//         return cnt;
//     }
//     if(i<m) return INT_MAX;

//     int take=INT_MAX;
    
//     take=min(take,ans(i/2,m,cnt+1));
//     if(i%2!=0) take=min(take,ans(i/2 +1,m,cnt+1));
    
//     return take;
// }

// void solve() {
//     int n, m;
//     cin >> n >>m ;
//     int hi=ans(n, m,0);
//     cout<<((hi>=INT_MAX) ? -1 : hi )<< endl;
//     }

// GAVE TLE
 
 unordered_map<int, int> dp;
const int INF = 1e9;

int ans(int i, int m) {
    if (i == m) return 0;
    if (i < m) return INF;

    if (dp.count(i)) return dp[i];

    int res = INF;

    res = min(res, 1 + ans(i / 2, m));
    if (i % 2 != 0)
        res = min(res, 1 + ans(i / 2 + 1, m));

    return dp[i] = res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    dp.clear();

    int hi = ans(n, m);
    cout << (hi >= INF ? -1 : hi) << '\n';
}




signed main() {
    ez;

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}