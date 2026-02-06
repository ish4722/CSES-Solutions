//good qus a bit to learn

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


//in this qus order matters so we cant put a loop directly so we kept a variable j to track the index of coin we are at
// int cal(int i,int j, vector<vector<int>> & dp,vector<int> & v){
//     if(i==0) return 1;
//     if(j==v.size()) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     int take=0;

//     if(i-v[j]>=0 ) take=cal(i-v[j],j,dp,v);
//     int nottake=cal(i,j+1,dp,v);

//     return dp[i][j]=(take+nottake)%mod;
// }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    // vector<vector<int>> dp(m+1, vector<int>(n, 0));

    // for(int i = 0; i < n; i++)
    //     dp[0][i] = 1;

    // for(int i = 0; i < n; i++) {
    //     for(int sum = 1; sum <= m; sum++) {

    //         if (i > 0)
    //             dp[sum][i] = dp[sum][i-1];

    //         if (sum - c[i] >= 0)
    //             dp[sum][i] = (dp[sum][i] + dp[sum - c[i]][i]) % mod;
    //     }
    // }

    // cout << dp[m][n-1] << endl;

    vector<int> dp(m+1, 0);
    dp[0] = 1;

    for(int coin : c) {
        for(int sum = coin; sum <= m; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % mod;
        }
    }

    cout << dp[m] << endl;
}

signed main() {
    ez;

    int t = 1;
    while (t--) solve();

    return 0;
}