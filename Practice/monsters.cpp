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

    vector<vector<char>> grid(n, vector<char>(m));
    queue<pair<int,int>> st,st2;

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<int>> dist2(n, vector<int>(m, -1));

    f(i,0,n) {
        f(j,0,m) {
            cin>>grid[i][j];

            if(grid[i][j]=='M') {
                dist[i][j]=0;
                st.push({i,j});
            }

            if(grid[i][j]=='A') {
                dist2[i][j]=0;
                st2.push({i,j});
            }
        }
    }

    vector<char> parent_dir={'U','D','L','R'};
    vector<vector<char>> parent(n, vector<char>(m,' '));
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};

    while(!st.empty()) {
        auto [x,y]=st.front();
        st.pop();

        for(int k=0;k<4;k++) {
            int nx=x+dir[k][0];
            int ny=y+dir[k][1];

            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;

            if(grid[nx][ny]=='#')
                continue;

            if(dist[nx][ny]!=-1)
                continue;

            dist[nx][ny]=dist[x][y]+1;
            st.push({nx,ny});
        }
    }

    while(!st2.empty()) {
        auto [x,y]=st2.front();
        st2.pop();

        if(x==0 || x==n-1 || y==0 || y==m-1) {
            cout<<"YES"<<endl;
            cout<<dist2[x][y]<<endl;

            string ans;

            while(parent[x][y]!=' ') {
                ans+=parent[x][y];

                if(parent[x][y]=='U') x++;
                else if(parent[x][y]=='D') x--;
                else if(parent[x][y]=='L') y++;
                else if(parent[x][y]=='R') y--;
            }

            reverse(ans.begin(),ans.end());

            cout<<ans<<endl;
            return;
        }

        for(int k=0;k<4;k++) {
            int nx=x+dir[k][0];
            int ny=y+dir[k][1];

            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;

            if(grid[nx][ny]=='#')
                continue;

            if(dist2[nx][ny]!=-1)
                continue;

            if(dist[nx][ny]!=-1 &&
               dist[nx][ny]<=dist2[x][y]+1)
                continue;

            dist2[nx][ny]=dist2[x][y]+1;
            parent[nx][ny]=parent_dir[k];

            st2.push({nx,ny});
        }
    }

    cout<<"NO"<<endl;
}

signed main() {
    ez;

    int t=1;
    while(t--)
        solve();

    return 0;
}