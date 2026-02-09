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


int dfs(int i, int j, vector<vector<char>>& matrix, int n,vector<vector<int>>& dp){
    if(i>=n || j>=n || matrix[i][j] == '*') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i==n-1 && j==n-1) return 1;
    return dp[i][j]= (dfs(i+1, j, matrix, n,dp) + dfs(i, j+1, matrix, n,dp))%mod;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));

    f(i,0,n) f(j,0,n) cin >> matrix[i][j];

    cout<<dfs(0, 0, matrix, n,dp)<<endl;

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}