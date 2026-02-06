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



//in this qus order doesnt matters so we put a loop directly and a single d was needed

int cal(int i,vector<int> & dp,vector<int> & v){
    if(i==0) return 1;
    if(i<0) return 0;

    if(dp[i] != -1) return dp[i];
    int ans=0;

    f(j,0,v.size()){
        ans=(ans+cal(i-v[j],dp,v))%mod;
    }

    return dp[i]=ans;
}

void solve() {
    int n,m;
    cin>>n>>m;
    getv(c,n);
    vector<int> dp(m+1,-1);

                                    // dp[0] = 1;
                                    // for (sum = 1 → x)
                                    //     for (coin in coins)
                                    //         dp[sum] += dp[sum - coin];
    cout<<cal(m,dp,c)<<endl;

}

signed main() {
    ez;

    int t = 1;

    while (t--) solve();

    return 0;
}