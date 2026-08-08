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

void solve() {
        int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    queue<int> q;
    f(i,0,m) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    f(i,1,n+1) {
        if(indegree[i] == 0) q.push(i);
    }
    vector<int> ans;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    vector<int> dp(n+1, 0);
    dp[1]=1;
    //dp[u] = number of paths to u
    for(int u:ans){
        for(int v:adj[u]){
            dp[v]+=dp[u];
            dp[v]%=mod;
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