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
#include <climits>

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
    cin>>n>>m;

    vector<vector<int>> adj(n+1);
    f(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1,-1);
    dist[1]=0;
    queue<pair<int,int>> q;
    q.push({1,0});

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    while(!q.empty()){
        auto [u,v] =q.front();
        q.pop();
        if(u==n) break;
        if(v>dist[u]) continue;
        for(auto &x: adj[u]){
            if(v+1<dist[x]){
                parent[x]=u;
                dist[x]=v+1;
                q.push({x,v+1});
            }
        }
    }
    if(dist[n]==INT_MAX){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    else {
        cout<<dist[n]+1<<endl;
        vector<int> ans;
        int curr=n;
        while(curr!=-1){
            ans.push_back(curr);
            curr=parent[curr];
        }
        reverse(all(ans));
        for(auto &x: ans) cout<<x<<" ";
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}