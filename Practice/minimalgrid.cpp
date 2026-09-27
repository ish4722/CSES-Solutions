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
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    f(i,0,n) {
        f(j,0,n) {
            cin >> grid[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0,0});

    vector<int> dx = {0,1};
    vector<int> dy = {1,0};

    string ans = "";
    ans += grid[0][0];

    while(!q.empty()) {

        int sz = q.size();
        char mini = 'z';

        vector<pair<int,int>> next_cells;
        while(sz--) {
            auto [x,y] = q.front();
            q.pop();

            f(i,0,2) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    mini = min(mini, grid[nx][ny]);
                    next_cells.push_back({nx,ny});
                }
            }
        }

        ans += mini;

        set<pair<int,int>> st;

        for(auto [nx,ny] : next_cells) {
            if(grid[nx][ny] == mini) {
                st.insert({nx,ny});
            }
        }

        for(auto cell : st) {
            q.push(cell);
        }

        if(ans.size() == 2*n-1) {
            cout << ans << '\n';
            return;
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