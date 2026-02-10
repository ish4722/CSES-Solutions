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


int cal(int i,int j,vector<int>& v,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int sum=0;
    sum=max(v[i]+min(cal(i+2,j,v,dp) , cal(i+1,j-1,v,dp)),v[j]+min(cal(i,j-2,v,dp),cal(i+1,j-1,v,dp)));
    return dp[i][j]= sum;
}
void solve() {
    int n;
    cin>>n;
    getv(v, n);
    // vector<vector<int>> dp(n,vector<int>(n,-1));
    // cout<<cal(0,n-1,v,dp)<<endl;
    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // length = 1
    for (int i = 0; i < n; i++)
        dp[i][i] = v[i];

    // length >= 2
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            long long take_i =
                v[i] +
                min(
                    (i + 2 <= j ? dp[i + 2][j] : 0),
                    (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
                );

            long long take_j =
                v[j] +
                min(
                    (i <= j - 2 ? dp[i][j - 2] : 0),
                    (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
                );

            dp[i][j] = max(take_i, take_j);
        }
    }

    cout << dp[0][n - 1] << "\n";
}


signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}