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

typedef vector<char> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vpi;

const int mod = 1000000007;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void solve() {
    int n,m;
    cin >> n >> m;

    vvi g(n, vi(m));

    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m,-1));
    vector<vector<int>> dist2(n, vector<int>(m,-1));

    f(i,0,n) {
        f(j,0,m) {
            char c;
            cin >> c;
            g[i][j] = c;
            if (c == 'M') {
                q.push({i,j});
                dist[i][j] = 0;
            } 
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;

        q.pop();

        f(k,0,4){
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && dist[ni][nj]==-1 && (g[ni][nj]=='.' || g[ni][nj]=='A')){
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }

    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<char> path={'D', 'U', 'R', 'L'};

    f(i,0,n) {
        f(j,0,m) {
            if (g[i][j]== 'A') {
                q.push({i,j});
                dist2[i][j] = 0;
            } 
        }
    }

    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        if(i==0 ||i==n-1 ||j==0 ||j==m-1){
            cout<<"YES"<<endl;
            string ans="";

            cout<<dist2[i][j]<<endl;

            while(parent[i][j]!=-1){
                ans+=path[parent[i][j]];
                int ni=i-dx[parent[i][j]];
                int nj=j-dy[parent[i][j]];
                i=ni;
                j=nj;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans<<endl;
            exit(0);   
        }

        f(k,0,4){
            int ni= i + dx[k];
            int nj= j + dy[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && dist2[ni][nj]==-1 && g[ni][nj]=='.' && (dist[ni][nj] == -1 ||dist2[i][j] +1 < dist[ni][nj])){
                dist2[ni][nj] = dist2[i][j] + 1;
                parent[ni][nj] = k;
                q.push({ni,nj});
            }
        }
    }
    cout << "NO\n";
}

signed main() {
    ez;

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}