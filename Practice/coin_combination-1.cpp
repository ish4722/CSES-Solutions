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


int cal(int sum,vector<int>& dp,vector<int>&coins,int x){
    if(sum==x)return 1;
    if(sum>x)return 0;
    if(dp[sum]!=-1) return dp[sum];

    int ans=0;
    for(int j=0;j<coins.size();j++){
        ans=(ans+cal(sum+coins[j],dp,coins,x))%mod;
    }
    return dp[sum]=ans;
}
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    f(i,0,n) cin>>coins[i];
    vector<int> dp(x+1,0);
    dp[x]=1;

    for(int sum=x-1;sum>=0;sum--){
        for(int coin:coins){
            if(sum+coin<=x){
                dp[sum]=(dp[sum]+dp[sum+coin])%mod;
            }
        }
    }
    cout<<dp[0]<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}