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

    vector<vector<pair<int,int>>> flights(n+1);
    f(i,0,m) {
        int u,v,c;
        cin>>u>>v>>c;
        flights[u].push_back({v,c});
    }
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    vector<vector<int>> dist(n+1, vector<int>(2, 1e18));

    pq.push({0,{1,0}});
    dist[1][0]=0;

    while(!pq.empty()){
        auto [d,p]=pq.top();
        pq.pop();

        int u=p.first;
        int used=p.second;

        if(d>dist[u][used]) continue;

        for(auto i:flights[u]){
            int v=i.first;
            int c=i.second;

            if(dist[v][used]>d+c){
                dist[v][used]=d+c;
                pq.push({dist[v][used],{v,used}});
            }

            if(used==0 && dist[v][1]>d+c/2){
                dist[v][1]=d+c/2;
                pq.push({dist[v][1],{v,1}});
            }
        }
    }
    cout<<min(dist[n][0],dist[n][1])<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}