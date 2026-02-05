//good qustion, bfs, backtracking

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

int n, m;
vector<string> grid;
bool visited[1000][1000];
char parentDir[1000][1000];   // direction used to reach this cell
pair<int,int> parentCell[1000][1000];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

int main() {
    cin >> n >> m;
    grid.resize(n);

    pair<int,int> start, end;

    for(int i = 0; i < n; i++) {
        cin >> grid[i];
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') start = {i, j};
            if(grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(grid[nx][ny] == '#' || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            parentDir[nx][ny] = dir[i];
            parentCell[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }

    if(!visited[end.first][end.second]) {
        cout << "NO\n";
        return 0;
    }

    // Backtrack path
    string path;
    pair<int,int> cur = end;

    while(cur != start) {
        path.push_back(parentDir[cur.first][cur.second]);
        cur = parentCell[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
}
