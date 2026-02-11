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

// good qus for binary in dp 
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


int cal(int i,int j, vector<pair<pair<int,int>,int>>& v, vector<vector<int>>& dp) {
    if(i==v.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int take=0;
    if(v[i].first.first>j) {
        take = v[i].second + cal(i+1,v[i].first.second,v,dp);
    }
    int nottake = cal(i+1,j,v,dp);
    return dp[i][j] = max(take,nottake);
}
void solve() {
    int n;
    cin >> n;
    // vector<pair<pair<int,int>,int>> v(n);
    // f(i,0,n) {
    //     cin >> v[i].first.first >> v[i].first.second;
    //     cin>> v[i].second;
    // }

    // vector<vector<int>> dp(n, vector<int>(1000001,-1));
    // cout << cal(0,0,v,dp) << endl;

    vector<vector<int>> v(n, vector<int>(3));
    f(i,0,n) {
        cin >> v[i][1] >> v[i][0] >> v[i][2];
    }
    sort(all(v));

    vector<int> end(n);
    f(i,0,n) end[i] = v[i][0];

    vector<int> dp(n+1,0);
// dp[i] = maximum money we can earn using only the first i projects
    f(i,1,n+1) {
        int idx = lower_bound(all(end),v[i-1][1]) - end.begin(); // Find last project that ends before start
        dp[i] = max(dp[i-1], dp[idx] + v[i-1][2]);
    }
    cout << dp[n] << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}