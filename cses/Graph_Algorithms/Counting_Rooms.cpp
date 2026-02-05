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


void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>>& grid){
    int n=grid.size();
    int t=grid[0].size();

    if(i<0 || j<0 || i>=n || j>=t || vis[i][j] || grid[i][j]=='#') return;
    vis[i][j]=true;

    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    for(auto &d:dir){
        dfs(i+d.first,j+d.second,vis,grid);
    }
}
void solve() {
    int n,t;
    cin>>n>>t;
    vector<vector<char>> grid(n, vector<char>(t));
    f(i,0,n) f(j,0,t) cin>>grid[i][j];

    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(t, false));
    
    f(i,0,n) f(j,0,t){
        if(!vis[i][j] && grid[i][j]=='.'){
            ans++;
            dfs(i,j,vis,grid);
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}