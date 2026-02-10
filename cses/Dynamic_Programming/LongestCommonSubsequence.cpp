//here we learn to print subsequence 
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


int cal(int i,int j, vector<vector<int>>& dp,vector<int>& a,vector<int>& b){
    if(i == 0 || j ==  0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i-1] == b[j-1])
        return dp[i][j] = 1 + cal(i-1, j-1, dp, a, b);
    else
        return dp[i][j] = max(cal(i-1, j, dp, a, b),cal(i, j-1, dp, a, b));
}

void solve() {
    int a,b;
    cin>>a>>b;
    getv(m,a);
    getv(n,b);

    vector<vector<int>> dp(a+1,vector<int>(b+1,-1));

    cout<<cal(a,b,dp,m,n)<<endl;
    vector<int> ans;

    while(a>0 && b>0){
        if(m[a-1]==n[b-1]) {
            ans.push_back(m[a-1]);
            a--;
            b--;
        }
        else if(dp[a-1][b] > dp[a][b-1]){
            a--;
        }
        else b--;
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}