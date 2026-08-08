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

//though its a DAG WE MAY USE PQ,AS WE ARE KEEPING 
// A CNT ARRAY TO LIMIT A NUMBER OF NODE USE
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);

    f(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    vector<int>cnt(n+1,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,1});
    cnt[1] = 0;
    priority_queue<int, vector<int>, greater<int>> ans;
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if(u==n) ans.push(d);
        if(cnt[u]==k) continue;
// How many shortest paths to this node have been finalized?
// A path is finalized only when it is popped, not when it is pushed.
        cnt[u]++;
        for(auto [v,w]: adj[u]){
            if(cnt[v]<k){

                pq.push({d+w,v});
            }
        }
    }
    while(k--) {
        if(ans.empty()) cout<<-1<<endl;
        else{
            cout<<ans.top()<<endl;
            ans.pop();
        }
    }

}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}