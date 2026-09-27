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


int farthest_node=0;
void dfs(int i,int p, vector<vector<int>>& adj, vector<int>& depth){
    for(int j:adj[i]){
        if(j==p) continue;
        depth[j]=depth[i]+1;
        if(depth[j]>depth[farthest_node]) farthest_node=j;
        dfs(j,i,adj,depth);
    }
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adj(n);

    f(i,0,n-1){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n,0),depthA(n,0),depthB(n,0);
    dfs(0,-1,adj,depth);
    int A=farthest_node;
    farthest_node=A;
    dfs(A,-1,adj,depthA);
    int B=farthest_node;
    dfs(B,-1,adj,depthB);

    f(i,0,n){
        cout<<max(depthA[i],depthB[i])<< " ";
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}