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

int dp_cal(int n,vector<int> &dp){
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    int ans = 0;
    for(int i=1; i<=6; i++) {
        if(n-i >= 0) {
            ans = (ans + dp_cal(n-i, dp)) % mod;
        }
    }
    return dp[n]=ans;
}

void solve() {
    int n;
    cin>>n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    f(i,1,n+1) {
        for(int j=1; j<=6; j++) {
            if(i-j >= 0) {
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    cout<<dp[n]<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}