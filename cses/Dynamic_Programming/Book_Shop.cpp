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


// int cal(int i,int j,vector<vector<int>> &dp ,vector<int>& price, vector<int> &pages){
//     if (i < 0 || j == 0) return 0;
//     if(dp[i][j] != -1) return dp[i][j];
//     int take=0;
//     if(j-price[i]>=0) take=pages[i]+cal(i-1, j-price[i], dp, price, pages);
//     int nontake=cal(i-1, j, dp, price, pages);
//     return dp[i][j] = max(take, nontake);
// }

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> price(n), pages(n);
    f(i,0,n) cin >> price[i];
    f(i,0,n) cin >> pages[i];

    // vector<vector<int>> dp(n, vector<int>(m+1, 0));
    // //this was like at i==0 sum must be atleast price[0] to take the book
    // f(j,0,m+1){
    //     if(j-price[0]>=0) dp[0][j]=pages[0];
    //     else
    //     dp[0][j] = 0;
    // }
    // f(i,1,n){
    //     f(j,0,m+1){
    //         int take=0;
    //         if(j-price[i]>=0) take=pages[i]+dp[i-1][j-price[i]];
    //         int nontake=dp[i-1][j];
    //         dp[i][j] = max(take, nontake);
    //     }
    // }
    // cout<<dp[n-1][m]<<endl;

    vector<int> prev(m+1, 0), curr(m+1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            int take = (j >= price[i]) ? pages[i] + prev[j - price[i]] : 0;
            int nontake = prev[j];
            curr[j] = max(take, nontake);
        }
        prev = curr;
    }

    cout << prev[m] << endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}