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

int cal(int i,int j, vector<int>& a,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    dp[i][j]=max(a[i]+min(cal(i+2,j,a,dp),cal(i+1,j-1,a,dp)),
                 a[j]+min(cal(i+1,j-1,a,dp),cal(i,j-2,a,dp)));

    return dp[i][j];
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];

    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++) dp[i][i]=a[i];

    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;

            dp[i][j]=max(a[i]+min((i+2<=j?dp[i+2][j]:0),(i+1<=j-1?dp[i+1][j-1]:0)),
                         a[j]+min((i+1<=j-1?dp[i+1][j-1]:0),(i<=j-2?dp[i][j-2]:0)));
        }
    }

    cout<<dp[0][n-1]<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}