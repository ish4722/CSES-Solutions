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
//good qus to practice BFS and greedy

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int,int>> q;

    q.push({0,0});
    visited[0][0] = true;

    string ans;
    ans.push_back(grid[0][0]);

    while (!q.empty()) {
        int sz = q.size();
        char best = 'z';
        vector<pair<int,int>> cand;

        // 🔹 explore exactly one BFS layer
        while (sz--) {
            auto [x,y] = q.front(); q.pop();

            if (x+1 < n && !visited[x+1][y]) {
                best = min(best, grid[x+1][y]);
                cand.push_back({x+1,y});
            }
            if (y+1 < n && !visited[x][y+1]) {
                best = min(best, grid[x][y+1]);
                cand.push_back({x,y+1});
            }
        }

        if (cand.empty()) break;  

        // 🔹 push only best characters
        for (auto [x,y] : cand) {
            if (!visited[x][y] && grid[x][y] == best) {
                visited[x][y] = true;
                q.push({x,y});
            }
        }

        ans.push_back(best);
    }

    cout << ans << "\n";
}
