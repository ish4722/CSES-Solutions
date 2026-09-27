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


pair<int,int> cal(int mask, int w, vector<int>& v, int W,vector<pair<int,int>>& dp){

    int n=v.size();
    if(mask==(1<<n)-1) return {1,w};

    if(dp[mask].first!=-1) return dp[mask];

    pair<int,int> ans={1e9,1e9};

    for(int i=0;i<n;i++){

        if(mask&(1<<i)) continue;
        pair<int,int> cur;

        if(w+v[i]<=W){
            cur=cal(mask|(1<<i),w+v[i],v,W,dp);
        }
        else{
            cur=cal(mask|(1<<i),v[i],v,W,dp);
            cur.first++;
        }

        if(cur.first<ans.first ||(cur.first==ans.first && cur.second<ans.second))
            ans=cur;
    }

    return dp[mask]=ans;
}
void solve() {
    
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}