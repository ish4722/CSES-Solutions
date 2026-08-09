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
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);

    f(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(n+1,0); 
    pq.push({0,1});
    int sum=0;
    int cnt=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int node=p.second;
        int wt=p.first;

        if(vis[node]) continue;
        vis[node]=1;
        cnt++;
        sum+=wt;
        for(auto i:adj[node]){
            if(!vis[i.first]){
                pq.push({i.second,i.first});
            }
        }
    }
    if (cnt != n) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout<<sum<<'\n';
    }
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}