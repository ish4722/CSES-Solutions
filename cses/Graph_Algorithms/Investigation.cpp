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

    vector<vector<pair<int,int>>> adj(n+1);
    f(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }


    vector<int> dist(n+1, LLONG_MAX);
    vector<int> count(n+1, 0);
    vector<int> min_edges(n+1, LLONG_MAX);
    vector<int> max_edges(n+1, LLONG_MIN);

    dist[1] = 0;
    count[1] = 1;
    min_edges[1] = 0;
    max_edges[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d>dist[u]) continue;

        for(auto [v,edgwt]:adj[u]){
            if(dist[u]+edgwt <dist[v]){
                dist[v]=dist[u]+edgwt;
                count[v]=count[u];
                min_edges[v]=min_edges[u]+1;
                max_edges[v]=max_edges[u]+1;
                pq.push({dist[v],v});
            }
            else if(dist[u]+edgwt==dist[v]){
                count[v]=(count[v]+count[u])%mod;
                min_edges[v]=min(min_edges[v], min_edges[u]+1);
                max_edges[v]=max(max_edges[v], max_edges[u]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<count[n]<<" "<<min_edges[n]<<" "<<max_edges[n]<<endl;
    
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}